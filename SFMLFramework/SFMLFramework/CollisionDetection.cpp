#include "CollisionDetection.h"
#include "Helpers.h"
#include "Settings.h"

CollisionDetection::CollisionDetection()
    :m_collided     ( false )
{
    // Manualy load sounds in 
    m_deathAlienSound.load( "Assets/Audio/alien death.wav" );
    m_deathPlayerSound.load( "Assets/Audio/playerDeath.wav" );
}

CollisionDetection::CollisionDetection( const sf::SoundBuffer& alienEffect, const sf::SoundBuffer& playerEffect )
    : m_collided            ( false )
    ,m_deathAlienSound      ( alienEffect )
    ,m_deathPlayerSound     ( playerEffect )
{
}

CollisionDetection::~CollisionDetection()
{
    //Decontructor 
}

void CollisionDetection::update( ObjectManager& pool, AlienWave& wave, PlayerShip& player, PlayerData& playerData )
{
    // Loop through and check each bullet to see if it collides with any aliens
    for ( int bulletCount = 0; bulletCount < Settings::k_amountOfBullets;bulletCount++ )
    {
        for ( int row = 0; row < wave.getGridSize().x; row++ )
        {
            for ( int col = 0; col < wave.getGridSize().y; col++ )
            { 
                // Check if bullets active check if alien is not null or dead. 
                if ( pool.getBullet()[bulletCount].getActiveState() && wave.getAlienArray()[row][col] != nullptr && wave.getAlienArray()[row][col]->getState() != AlienStatus::Dead )
                {
                    // Check to see if they are colliding and the bullet is active 
                    if ( pool.getBullet()[bulletCount].getPlayerFired() == true  )
                    {
                         m_collided = checkCollision( pool.getBullet()[bulletCount], *wave.getAlienArray()[row][col] );

                       if ( m_collided == true )
                       {
                           // If colliding set alien to dead an remove bullet from object pool.
                           wave.getAlienArray()[row][col]->setState( AlienStatus::Dead );
                           pool.getBullet()[bulletCount].setActiveState( false );

                           // Update score depending on what alien the player hit 
                           playerData.setScore( playerData.getScore() + wave.getAlienArray()[row][col]->getDestroyScore() );

                           // Play Death Sound 
                           m_deathAlienSound.play();
                       }
                    }

                }
            }
            if ( pool.getBullet()[bulletCount].getPlayerFired() == false && pool.getBullet()[bulletCount].getActiveState() == true&& player.getRespawning() == false )
            {
                // Check collision between player and bullet
                m_collided = checkCollision( pool.getBullet()[bulletCount], player );

                // If player did not fire bullet and collision happen take a life from player. Also ensure the bullet is active  
                if ( m_collided == true  )
                {
                    player.setLives( player.getLives() - 1 );
                    m_deathPlayerSound.play();
                    player.respawn();
                }
            }
        }

    }
    // Checking for a collision between  all aliens and player 
    for ( int row = 0; row < wave.getGridSize().x; row++ )
    {
        for ( int col = 0; col < wave.getGridSize().y; col++ )
        {
            // If alien is not null and not dead && player not respawning 
            if ( wave.getAlienArray()[row][col] != nullptr && wave.getAlienArray()[row][col]->getState() != AlienStatus::Dead && player.getRespawning() == false )
            {
                // check collision for this player 
                m_collided = checkCollision( *wave.getAlienArray()[row][col], player );
                if ( m_collided == true )
                {
                    // If hit respawn player and take away a life 
                    player.setLives( player.getLives() - 1 );
                    player.respawn();
                    m_deathPlayerSound.play();
                }
            }
        }

    }
}
bool CollisionDetection::checkCollision( const GameSprite& gameObjectOne,const GameSprite& gameObjectTwo )
{
    // Get the radius of the first Game Object by getting the average of half the width/height 
    float radiiOne = ( ( gameObjectOne.getTextureDimensions().x * 0.5f ) + ( gameObjectOne.getTextureDimensions().y * 0.5f ) * 0.5f );
    float radiiTwo = ( ( gameObjectTwo.getTextureDimensions().x * 0.5f ) + ( gameObjectTwo.getTextureDimensions().y * 0.5f ) * 0.5f);

    // Worked out the distance between both go origin points.
    float distanceBetweenCentresSquared = Math::distanceBetweenVectors( gameObjectOne.getPosition(), gameObjectTwo.getPosition() ) * Math::distanceBetweenVectors( gameObjectOne.getPosition(), gameObjectTwo.getPosition() );

    float sumOfRadii = radiiOne + radiiTwo;

    // Work out if the circles of the GO overlap with each other. This would show a collision if they did.
    if ( distanceBetweenCentresSquared < ( sumOfRadii * sumOfRadii ) )
    {
        // Circles are overlapping!
        return true;
    }
    else
    {
        // Circles are not overlapping
        return false;
    }
}
