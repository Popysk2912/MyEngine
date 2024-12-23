#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <glad/glad.h>
#include <SFML/Graphics/Texture.hpp>

#include "../shader.h"
#include "../texture.h"
#include <filesystem>

class ResourceManager
{
public:
    static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, const std::string& name);
    static Shader GetShader(const std::string& name);    

    static Texture2D LoadTexture(const char* file, const std::string& name);
    static Texture2D GetTexture(const std::string &name);

    static std::vector<Texture2D> LoadTileTexture(const char* file);
    static std::vector<Texture2D>& GetTileTextures();
    static Texture2D GetTileTexture(int index);

    static std::vector<std::vector<int>> LoadMatrixFromFile(const std::string &fileName, int ROWS, int COLS);
    
    static void Clear();
    static void Init();

    static std::string GetResourcePath();

private:
    ResourceManager() = default;

    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;
    static std::vector<Texture2D> tileTextures;
    static std::string resource_path;
    
    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
    static Texture2D loadTextureFromFile(const char* file);

    static unsigned char* textureToCharArray(const sf::Image& image, int& width, int& height);
    static void replaceChar(std::string& str, char oldChar, char newChar);
    static std::filesystem::path getPath();

};

#endif // RESOURCE_MANAGER_H
