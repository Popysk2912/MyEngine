#include "CollisionManager.h"

#include <algorithm>

void CollisionManager::resolveCollision(Sprite& first, const Sprite& other)
{
    if ((first.getBoundingBox().intersects(other.getBoundingBox()) && (first.getCollision() && other.getCollision())))
    {
        const auto firstBox = first.getBoundingBox();
        const auto otherBox = other.getBoundingBox();

        const float overlapX = std::min(firstBox.right(), otherBox.right()) - std::max(firstBox.left(), otherBox.left());
        const float overlapY = std::min(firstBox.top(), otherBox.top()) - std::max(firstBox.bottom(), otherBox.bottom());

        constexpr float epsilon = 0.001f;
        if (std::abs(overlapX - overlapY) < epsilon) {
            if (firstBox.center().x < otherBox.center().x) {
                first.setPosition(glm::vec2{otherBox.left() - firstBox.width, firstBox.y});
            } else {
                first.setPosition(glm::vec2{otherBox.right(), firstBox.y});
            }

            if (firstBox.center().y < otherBox.center().y) {
                first.setPosition(glm::vec2{firstBox.x, otherBox.bottom() - firstBox.height});
            } else {
                first.setPosition(glm::vec2{firstBox.x, otherBox.top()});
            }

            first.setVelocity(glm::vec2{0, 0});
        }
        else if (overlapX < overlapY) {
            if (firstBox.center().x < otherBox.center().x) {
                first.setPosition(glm::vec2{otherBox.left() - firstBox.width, firstBox.y});
            } else {
                first.setPosition(glm::vec2{otherBox.right(), firstBox.y});
            }
            first.setVelocity(glm::vec2{0, first.getVelocity().y});
        }
        else {
            if (firstBox.center().y < otherBox.center().y) {
                first.setPosition(glm::vec2{firstBox.x, otherBox.bottom() - firstBox.height});
            } else {
                first.setPosition(glm::vec2{firstBox.x, otherBox.top()});
            }
            first.setVelocity(glm::vec2{first.getVelocity().x, 0});
        }
    }
}


/*void CollisionManager::resolveCollision(TileMap& map, GameObject& first)
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
                        first.setPosition(glm::vec2(otherBox.x - firstBox.width, firstBox.y));
                    }
                    else {
                        first.setPosition(glm::vec2(otherBox.right(), firstBox.y));
                    }
                    first.setVelocity(glm::vec2(0, first.getVelocity().y));
                }
                else {
                    if (firstBox.center().y < otherBox.center().y) {
                        first.setPosition(glm::vec2(firstBox.x, otherBox.y - firstBox.height));
                    }
                    else {
                        first.setPosition(glm::vec2(firstBox.x, otherBox.bottom()));
                    }
                    first.setVelocity(glm::vec2(first.getVelocity().x, 0));
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
                        first.setPosition(glm::vec2(otherBox.x - firstBox.width, firstBox.y));
                    }
                    else {
                        first.setPosition(glm::vec2(otherBox.right(), firstBox.y));
                    }
                    first.setVelocity(glm::vec2(0, first.getVelocity().y));
                }
                else {
                    if (firstBox.center().y < otherBox.center().y) {
                        first.setPosition(glm::vec2(firstBox.x, otherBox.y - firstBox.height));
                    }
                    else {
                        first.setPosition(glm::vec2(firstBox.x, otherBox.bottom()));
                    }
                    first.setVelocity(glm::vec2(first.getVelocity().x, 0));
                }
            }
        }
}*/