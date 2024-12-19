#include "ResourceManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture2D> ResourceManager::Textures;
std::vector<Texture2D> ResourceManager::tileTextures;
std::string ResourceManager::resource_path;

Shader ResourceManager::LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, const std::string& name)
{
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}

Shader ResourceManager::GetShader(const std::string& name)
{
    auto it = Shaders.find(name);
    if (it != Shaders.end())
        return it->second;

    std::cerr << "ERROR::SHADER: Shader not found with name " << name << std::endl;
    return {};
}

Texture2D ResourceManager::LoadTexture(const char* file, const std::string& name)
{
    Textures[name] = loadTextureFromFile(file);
    return Textures[name];
}

Texture2D ResourceManager::GetTexture(const std::string& name)
{
    auto it = Textures.find(name);
    if (it != Textures.end())
        return it->second;

    std::cerr << "ERROR::Texture: Texture not found with name " << name << std::endl;
    return {};
}

std::vector<Texture2D> ResourceManager::LoadTileTexture(const char* file)
{
    tileTextures.push_back(loadTextureFromFile(file));
    return tileTextures;
}

std::vector<Texture2D>& ResourceManager::GetTileTextures()
{
    return tileTextures;
}

Texture2D ResourceManager::GetTileTexture(const int index)
{
    return tileTextures[index];
}

Shader ResourceManager::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile)
{
    std::string vertexCode, fragmentCode, geometryCode;

    try
    {
        std::ifstream vertexShaderFile(resource_path + "/" + vShaderFile), fragmentShaderFile(resource_path + "/" + fShaderFile);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

        if (gShaderFile)
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryCode = gShaderStream.str();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "ERROR::SHADER: Failed to read shader files: " << e.what() << std::endl;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    const char* gShaderCode = gShaderFile ? geometryCode.c_str() : nullptr;

    Shader shader;
    shader.Compile(vShaderCode, fShaderCode, gShaderFile ? gShaderCode : nullptr);
    return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char* file)
{
    Texture2D texture;
    texture.Internal_Format = GL_RGBA;
    texture.Image_Format = GL_RGBA;

    int width = 0, height = 0;
    sf::Image image;
    image.loadFromFile(resource_path + "/" + file);
    unsigned char* data = textureToCharArray(image, width, height);

    if (data)
    {
        texture.Generate(width, height, data);
        delete[] data;
    }
    else
    {
        std::cerr << "ERROR::TEXTURE: Failed to generate texture for " << file << std::endl;
    }

    return texture;
}

void ResourceManager::Clear()
{
    for (auto iter : Shaders)
        glDeleteProgram(iter.second.ID);
    for (auto iter : Textures)
        glDeleteTextures(1, &iter.second.ID);
}

void ResourceManager::Init()
{
#ifdef NDEBUG
    auto exePath = std::filesystem::current_path().string();
    replaceChar(exePath, '\\', '/');
    auto resourcePath = exePath + "/resources";
#else
    auto dirPath = getPath().string();
    replaceChar(dirPath, '\\', '/');
    auto resourcePath = dirPath + "/resources";
#endif
    std::cout << "Resource Path: " << resourcePath << "\n";
    resource_path = resourcePath;
}

std::string ResourceManager::GetResourcePath()
{
    return resource_path;
}

unsigned char* ResourceManager::textureToCharArray(const sf::Image& image, int& width, int& height)
{
    const sf::Uint8* pixels = image.getPixelsPtr();
    const unsigned int width_ = image.getSize().x;
    const unsigned int height_ = image.getSize().y;

    constexpr int nrChannels = 4;
    const size_t size = width_ * height_ * nrChannels;

    const auto pixelArray = new unsigned char[size];
    std::memcpy(pixelArray, pixels, size);

    width = width_;
    height = height_;

    return pixelArray;
}

void ResourceManager::replaceChar(std::string& str, const char oldChar, const char newChar)
{
    for (char& c : str)
    {
        if (c == oldChar)
        {
            c = newChar;
        }
    }
}

std::filesystem::path ResourceManager::getPath()
{
    std::string target = PROJECT_NAME;
    std::filesystem::path currentPath = std::filesystem::current_path();
    while (currentPath.filename().string() != target)
    {
        currentPath = currentPath.parent_path();
    }
    return currentPath;
}

std::vector<std::vector<int>> ResourceManager::LoadMatrixFromFile(const std::string &fileName, const int ROWS, const int COLS)
{
    std::vector<std::vector<int>> matrix;
    matrix.resize(ROWS);
    std::ifstream file(resource_path + "/" + fileName);
    if (!file.is_open()) {
        std::cout << "Can't open file: " << fileName << "." << "\n";
        return std::vector<std::vector<int>>(0);
    }
    for (int i = 0; i < ROWS; i++)
    {
        matrix[i].resize(COLS);
        for (int j = 0; j < COLS; j++)
            file >> matrix[i][j];
    }
    file.close();
    return matrix;
}
