#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
#include <Screen.hpp>

/*
Code taken from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
Altered by Team 2 for birdquest
*/
    //original had const int* tiles; now changed to const char*
    bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const char* tiles, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset)){
            return false;
          }

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        int k = 0;
        std::stringstream stream(tiles);
        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
              int n;
              stream >> n;
              stream.ignore(1, ',');
              //std::cout << "Found integer: " << n << "\n";

              // get the current tile number
              int tileNumber = n;

              /*
              while(tiles[k] - 48 < 0){
                k++;
              }
              tileNumber = tiles[k] - 49;
              k++;
              */


              // find its position in the tileset texture
              int row = ceil(tileNumber / 16.0); // row
              int col = (tileNumber%16); //column
              row -= 1;
              col -= 1;

              //std::cout << tileNumber << " " << row << " " << col << std::endl;

              int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
              int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
              //std::cout << m_tileset.getSize().x << " tu " << tu << " tv " << tv << std::endl;

              // get a pointer to the current tile's quad
              sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

              // define its 4 corners; i and j are switched from original code
              quad[0].position = sf::Vector2f(j * tileSize.x, i * tileSize.y);
              quad[1].position = sf::Vector2f((j + 1) * tileSize.x, i * tileSize.y);
              quad[2].position = sf::Vector2f((j + 1) * tileSize.x, (i + 1) * tileSize.y);
              quad[3].position = sf::Vector2f(j * tileSize.x, (i + 1) * tileSize.y);

              // define its 4 texture coordinates
              quad[0].texCoords = sf::Vector2f(col * tileSize.x, row * tileSize.y);
              quad[1].texCoords = sf::Vector2f((col + 1) * tileSize.x, row * tileSize.y);
              quad[2].texCoords = sf::Vector2f((col + 1) * tileSize.x, (row + 1) * tileSize.y);
              quad[3].texCoords = sf::Vector2f(col * tileSize.x, (row + 1) * tileSize.y);

              //std::cout << m_vertices[(i+j*width)*4].texCoords.x << std::endl;
              //std::cout << quad[0].position.x << " " << quad[0].position.y << " " << quad[0].texCoords.x << " " << quad[0].texCoords.y << std::endl;
            }

        return true;
    }

    bool TileMap::load(Screen thisScreen){
      return true;
    }

    TileMap::~TileMap() = default;

    void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    int TileMap::getTexCoord(int x, int y){
      int n = ((y/16)+((x/16)*40))*4;
      std::cout << " n " << n << std::endl;
      return m_vertices[n].texCoords.x;
    }
