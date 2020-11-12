
#ifndef SENSOR_H
#define SENSOR_H

#if defined(__cplusplus)
extern "C"
{
#endif

   void Init_Sensor(void);
   float Read_Sensor(char Sensor);
   void Clear_sensor(void);

#if defined(__cplusplus)
}
#endif

#endif
