#ifndef PLAYER__H
#define PLAYER__H
#include <string>
#include <vector>
#include "twoWayMultisprite.h"
#include "bulletsPool.h"
#include "collisionStrategy.h"

class ExplodingSprite;
class Player : public TwoWayMultiSprite {
public:

  Player(const std::string&);
  Player(const Player&);
  virtual ~Player();

  virtual void draw() const;
  virtual void update(Uint32 ticks);
  void resetPosition();
  void setState(int state);
  int getState(){ return currState; }
  
  void stop();
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
  
  void increaseVelocity(float scale);
  void decreaseVelocity(float scale);

  void shoot();
  virtual void explode();
    
  bool collidedWithBullets(const Drawable* d);
  bool collidedWith(const Drawable* d);
  
  unsigned int getBulletCount() const {return bullets.getBulletlistCount();}
  unsigned int getFreeCount() const {return bullets.getFreelistCount();}
  
  void updateState();
  
  void toggleGodMode(){ godMode = !godMode; }
  bool getGodMode() { return godMode;}
  
  int getScore() { return score;}
  
  enum PLAYER_STATES{
      IDLE,
      WALK,
      EXPLODE,
      VANISH,
      WON,
      LOSE
  };
    
private:
    
  void move(const float& incr);
  int currState;
  bool keyPressed;
  bool keyPresseda;
  bool keyPresseds;
  bool keyPressedd;
  bool keyPressedw;
  int yBound;
  
  //MultiBullet
  std::string bulletName;
  float bulletSpeed;
  BulletsPool bullets;
  bool isExploding;
  ExplodingSprite* explosion;
  PerPixelCollisionStrategy strategy;
  bool godMode;
  int score;
  
  Player& operator=(const Player&);
};

#endif
