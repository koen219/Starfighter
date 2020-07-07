// consoleapp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include<cmath>
#include "player.h"
#include "laser.h"
#include "astroids.h"

const int Height = 768; //ik moet dit ookveranderen in collision dingen!
const int Width = 512;

int main()
{
    sf::RenderWindow window(sf::VideoMode(Width,  Height), "Starfighter!");
    float dt = 0.1;
    Player player;
    player.mass = 5 ;
    player.Tex.loadFromFile("./player.png");
    player.Spr.setTexture(player.Tex);
    sf::Sprite sprFireball;
    sf::Texture texFireball;
    texFireball.loadFromFile("./vuurbal.png");
    sprFireball.setTexture(texFireball);

    laser lasers;

    astroids astroid;
    astroid.bullets = &lasers;
    astroid.newAstroid(vector2D(128, 128), 270.2, 1.0);
    while (window.isOpen())
    {
        sf::Event event;
        vector2D appliedForce(0, 0);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();          
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            lasers.shoot(player.Position, player.Rotation, 2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.Rotation += 0.05;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.Rotation -= 0.05;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            appliedForce = vector2D(cos(3.1415 / 180.0 * player.Rotation), sin(3.1415 / 180.0 * player.Rotation)) * 3;
        }
        for (int i =0; i<10; i++){
            double speed = player.Velocity.magnitude();
            player.Force = player.Velocity * (-speed * speed)  + appliedForce;
            vector2D nextPos = player.getNextPos();
            if (nextPos.x < 16 or nextPos.x+ 16>Width) {
                appliedForce = player.collisionWithWall(1) * appliedForce.magnitude();
            }
            else {
                if (nextPos.y < 16 or nextPos.y + 16 > Height) {
                    appliedForce = player.collisionWithWall(2) * appliedForce.magnitude();
                }
                else {
                    player.move();
                }
            }
            /*if (nextPos.x >= 16 and nextPos.x + 16 < Width and nextPos.y >= 16 and nextPos.y + 16 < Height)
                player.move();
            else {
                appliedForce =player.collisionWithWall() * appliedForce.magnitude();
            }*/
            lasers.move();
            astroid.move();
        }
        player.Force = vector2D(0, 0);
        player.round();
        window.clear();
        if (!(appliedForce == vector2D(0.0, 0.0))) {
            sprFireball.setOrigin(8, 9);
            sprFireball.setRotation(180 + player.Rotation);

            vector2D firebalPos = player.Position + vector2D(cos(3.1415 / 180.0*player.Rotation),sin(3.1415 / 180.0*player.Rotation))*(-16);
            sprFireball.setPosition(firebalPos.x, firebalPos.y);
            window.draw(sprFireball);
        }

        lasers.draw(&window);
        astroid.draw(&window);
        player.draw(&window);
        window.display();
    }

    return 0;
}
