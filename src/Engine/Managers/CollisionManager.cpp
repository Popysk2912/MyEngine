/*#include "CollisionManager.h"

#include <algorithm>

void CollisionManager::resolveCollision(GameObject& first, GameObject& other)
{
    if ((first.getBoundingBox().intersects(other.getBoundingBox()) && (first.collision && other.collision)))
    {
        auto firstBox = first.getBoundingBox();
        auto otherBox = other.getBoundingBox();

        float overlapX = std::min(firstBox.right(), otherBox.right()) - std::max(firstBox.x, otherBox.x);
        float overlapY = std::min(firstBox.bottom(), otherBox.bottom()) - std::max(firstBox.y, otherBox.y);

        if (overlapX < overlapY) {
            if (firstBox.center().x < otherBox.center().x) {
                first.setPosition(Vector2f{otherBox.x - firstBox.width, firstBox.y});
            }
            else {
                first.setPosition(Vector2f{otherBox.right(), firstBox.y});
            }
            first.setVelocity(Vector2f{0, first.getVelocity().y});
        }
        else {
            if (firstBox.center().y < otherBox.center().y) {
                first.setPosition(Vector2f{firstBox.x, otherBox.y - firstBox.height});
            }
            else {
                first.setPosition(Vector2f{firstBox.x, otherBox.bottom()});
            }
            first.setVelocity(Vector2f{first.getVelocity().x, 0});
        }
    }
}

void CollisionManager::resolveCollision(TileMap& map, GameObject& first)
{
    for (auto& sprites : map.getTiles())
        for (auto& other : sprites)
        {
            if ((first.getBoundingBox().intersects(other.getBoundingBox()) && (first.collision && other.collision)))
            {
                auto firstBox = first.getBoundingBox();
                auto otherBox = other.getBoundingBox();

                float overlapX = std::min(firstBox.right(), otherBox.right()) - std::max(firstBox.x, otherBox.x);
                float overlapY = std::min(firstBox.bottom(), otherBox.bottom()) - std::max(firstBox.y, otherBox.y);

                if (overlapX < overlapY) {
                    if (firstBox.center().x < otherBox.center().x) {
                        first.setPosition(Vector2f(otherBox.x - firstBox.width, firstBox.y));
                    }
                    else {
                        first.setPosition(Vector2f(otherBox.right(), firstBox.y));
                    }
                    first.setVelocity(Vector2f(0, first.getVelocity().y));
                }
                else {
                    if (firstBox.center().y < otherBox.center().y) {
                        first.setPosition(Vector2f(firstBox.x, otherBox.y - firstBox.height));
                    }
                    else {
                        first.setPosition(Vector2f(firstBox.x, otherBox.bottom()));
                    }
                    first.setVelocity(Vector2f(first.getVelocity().x, 0));
                }
            }
        }
}

void CollisionManager::resolveCollision(GameObject& first, TileMap& map)
{
    for (auto& sprites : map.getTiles())
        for (auto& other : sprites)
        {
            if ((first.getBoundingBox().intersects(other.getBoundingBox()) && (first.collision && other.collision)))
            {
                auto firstBox = first.getBoundingBox();
                auto otherBox = other.getBoundingBox();

                float overlapX = std::min(firstBox.right(), otherBox.right()) - std::max(firstBox.x, otherBox.x);
                float overlapY = std::min(firstBox.bottom(), otherBox.bottom()) - std::max(firstBox.y, otherBox.y);

                if (overlapX < overlapY) {
                    if (firstBox.center().x < otherBox.center().x) {
                        first.setPosition(Vector2f(otherBox.x - firstBox.width, firstBox.y));
                    }
                    else {
                        first.setPosition(Vector2f(otherBox.right(), firstBox.y));
                    }
                    first.setVelocity(Vector2f(0, first.getVelocity().y));
                }
                else {
                    if (firstBox.center().y < otherBox.center().y) {
                        first.setPosition(Vector2f(firstBox.x, otherBox.y - firstBox.height));
                    }
                    else {
                        first.setPosition(Vector2f(firstBox.x, otherBox.bottom()));
                    }
                    first.setVelocity(Vector2f(first.getVelocity().x, 0));
                }
            }
        }
}*/