// Box2DIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Box2D/Box2D.h>

int main()
{
    // Setup
    b2Vec2 gravity(0.0f, -9.8f);
    b2World* world = new b2World(gravity);

    // put things in the world

    // static body setup
    b2BodyDef groundBoxDef;
    groundBoxDef.position.Set(0.0f, -20.0f); // 20 units below center

    b2Body* groundBody = world->CreateBody(&groundBoxDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(20.0f, 1.0f); // 40x2 -- 20, 1
    groundBody->CreateFixture(&groundBox, 0.0f); // 0 density -- forces don't impact it

    // dynamic body -- falling box
    b2BodyDef fallingBoxDef;
    fallingBoxDef.position.Set(0.0f, 10.0f);
    fallingBoxDef.type = b2_dynamicBody;
    b2Body* fallingBody = world->CreateBody(&fallingBoxDef);

    b2PolygonShape fallingBox;
    fallingBox.SetAsBox(2.5f, 2.5f); // 5x5 -- 2.5, 2.5 

    b2FixtureDef fallingFixtureDef;
    fallingFixtureDef.shape = &fallingBox;
    fallingFixtureDef.density = 1.0f;
    fallingFixtureDef.friction = 0.3f;
    fallingBody->CreateFixture(&fallingFixtureDef);

    // *** Simulation loop ***

    // Eventually a more intentional game loop.
    while (true)
    {
        // See where the box is
        b2Vec2 boxPos = fallingBody->GetPosition();
        std::cout << "box (" << boxPos.x << ", " << boxPos.y << ")" << std::endl;

        // Have to advance time in the world or nothing happens!
        world->Step(
            1.0f / 60.0f,	// time step -- should be the same every time! (i.e., consistent fps)
            6,				// velocity iterations
            2				// position iterations	
        );

        // We'll clean up the output & have a true fixed time step next class.

    }

    delete world;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
