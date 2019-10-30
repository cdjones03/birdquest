#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED

#include <Screen.hpp>

/*
Based on code from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
*/

class TileMap : public sf::Drawable, public sf::Transformable {

public:

  bool load(const std::string& tileset, sf::Vector2u tileSize, const char* tiles, unsigned int width, unsigned int height);
  bool load(Screen thisScreen);
  virtual ~TileMap();
  int getTexCoord(int x, int y);

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
};

#endif
