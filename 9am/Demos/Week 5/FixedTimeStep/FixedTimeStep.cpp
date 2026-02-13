// FixedTimeStep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Box2D/Box2D.h>
#include <iomanip> // let us configure cout precision
#include <chrono> // include high res clock class

// I should probably make you all write these yourself, but it was bothering me to
// have a ton of code in main() so I figured might as well give you the helpers
// I wrote for myself.
// NOTE - these are pretty simplistic and uncommented. Do NOT count on them being
// exactly what you'll need for HW2!
#include "box2d_helpers.h"

int main()
{
    // Including <iomanip> let's us configure how cout behaves. Only need to do this once.
    std::cout << std::fixed << std::setprecision(3);
    
    // Setup the world & its bodies
    b2Vec2 gravity(0.0f, -9.8f);
	b2World* world = new b2World(gravity);
	b2Body* ground = CreateStaticBox(world, 0.0f, -10.0f, 50.0f, 5.0f);
	b2Body* fallingBox = CreateDynamicBox(world, 0.0f, 10.0f, 0.5f, 0.5f);

    // ** Setup to track time
    
    // Need to track time that has passed & be able to configure our time step
    float timeTracker = 0;
    const float PHYS_TIME_STEP = 1.0f / 60.0f;

    // Give us access to the clock
    std::chrono::high_resolution_clock clock;

    // Need current time and prev frame time
    std::chrono::steady_clock::time_point prevTime = clock.now();

    // auto keyword --- uses context at compile time to figure out the
    // appropriate type (based on the return type in this case)
    // Sometimes this improves readability. Sometimes it obfuscates it.
    // Once made, the type does NOT change
    auto currTime = clock.now();

    // *** Simulation loop ***

    // Eventually a more intentional game loop.
    while (true)
    {
        // Update time tracking
        prevTime = currTime;
        currTime = clock.now();
        auto changeSeconds = 
            std::chrono::duration_cast<std::chrono::duration<float>>(currTime - prevTime);
        float deltaTime = changeSeconds.count();

        //std::cout << deltaTime * 1000 << std::endl;

        timeTracker += deltaTime;
        //std::cout << timeTracker << std::endl;

        // ONLY step (and look at the box position) now and then
        if (timeTracker >= PHYS_TIME_STEP)
        {
            timeTracker -= PHYS_TIME_STEP;


            // Have to advance time in the world or nothing happens!
            world->Step(
                1.0f / 60.0f,	// time step -- should be the same every time! (i.e., consistent fps)
                6,				// velocity iterations
                2				// position iterations	
            );
        }
        // See where the box is
        b2Vec2 boxPos = fallingBox->GetPosition();
        std::cout << "box (" << boxPos.x << ", " << boxPos.y << ")" << std::endl;

    }

	delete world;
}

