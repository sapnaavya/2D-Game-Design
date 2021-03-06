#ifndef MULTISPRITE__H
#define MULTISPRITE__H
#include <string>
#include <vector>
#include "drawable.h"

class MultiSprite : public Drawable {
public:
  MultiSprite(const std::string&);
  MultiSprite(const std::string& name, const Vector2f& pos, const Vector2f& vel);
  MultiSprite(const std::string& name, const Vector2f& pos, const Vector2f& vel, const std::vector<Frame*>& fms, const int nFrameMul);
  MultiSprite(const std::string&, const std::vector<Frame *>& fms, const int nFrameMul = 1);
  MultiSprite(const MultiSprite&);
  virtual ~MultiSprite(){};
  
  //MultiSprite& operator=(const MultiSprite& m);

  virtual void draw() const;
  virtual void update(Uint32 ticks);
  virtual const Frame* getFrame() const { 
    return frames[currentFrame]; 
  }
  
  const std::vector<Frame *> getFrames() const { 
    return frames;
  }
  
protected:
  const std::vector<Frame *> frames;
  int worldWidth;
  int worldHeight;

  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  float timeSinceLastFrame;
  int frameWidth;
  int frameHeight;
    
  virtual void advanceFrame(Uint32 ticks);
};
#endif
