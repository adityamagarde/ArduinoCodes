#include <SPI.h>
#include <Pixy.h>

Pixy pixy;

#define X_CENTER        ((PIXY_MAX_X-PIXY_MIN_X)/2)
#define Y_CENTER        ((PIXY_MAX_Y-PIXY_MIN_Y)/2)

class ServoLoop
{
  public:
    ServoLoop(int32_t pgain, int32_t dgain);

    void update(int32_t error);

    int32_t m_pos;
    int32_t m_prevError;
    int32_t m_pgain;
    int32_t m_dgain;
};


ServoLoop panLoop(300, 500);
ServoLoop tiltLoop(500, 700);

ServoLoop::ServoLoop(int32_t pgain, int32_t dgain)
{
  m_pos = PIXY_RCS_CENTER_POS;
  m_pgain = pgain;
  m_dgain = dgain;
  m_prevError = 0x80000000L;
}

void ServoLoop::update(int32_t error)
{
  long int vel;
  char buf[32];
  if (m_prevError != 0x80000000)
  {
    vel = (error * m_pgain + (error - m_prevError) * m_dgain) >> 10;
    // sprintf(buf, "%ld\n", vel);
    //Serial.print(buf);
    m_pos += vel;
    if (m_pos > PIXY_RCS_MAX_POS)
      m_pos = PIXY_RCS_MAX_POS;
    else if (m_pos < PIXY_RCS_MIN_POS)
      m_pos = PIXY_RCS_MIN_POS;
  }
  m_prevError = error;
}



void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(7, HIGH);

  pixy.init();
}

int count ;

void loop()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  int32_t panError, tiltError;

  blocks = pixy.getBlocks();
  Serial.println(blocks);
  if (blocks == 0)
  {
    count++;
  }

  if (blocks)
  { count = 0;
    panError = X_CENTER - pixy.blocks[0].x;
    tiltError = pixy.blocks[0].y - Y_CENTER;

    panLoop.update(panError);
    tiltLoop.update(tiltError);
    pixy.setServos(panLoop.m_pos, tiltLoop.m_pos);

    i++;

    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i % 50 == 0)
    {
      sprintf(buf, "Detected %d:\n", blocks);

      Serial.print(buf);
      for (j = 0; j < blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf);
        pixy.blocks[j].print();

        if ( pixy.blocks[j].width > 60 && pixy.blocks[j].width < 75)
        {
          if (pixy.blocks[j].height > 60 && pixy.blocks[j].height < 75)
          {
            digitalWrite(6, LOW);//stop
            digitalWrite(5, LOW);
          }
        }

        if ( pixy.blocks[j].width < 60 && pixy.blocks[j].height < 60)
        {
          digitalWrite(6, HIGH);//follow
          digitalWrite(5, LOW);
        }

        if ( pixy.blocks[j].width > 75 && pixy.blocks[j].height > 75)
        {
          digitalWrite(6, LOW);//reverce
          digitalWrite(5, HIGH);
        }
       
      }

    }

  }
  if (count > 100)
  {
    digitalWrite(6, HIGH);//break
    digitalWrite(5, HIGH);
    count = 0;
  }



}

