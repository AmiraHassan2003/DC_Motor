/* 
 * File:   ecu_dcMotor.h
 * Author: ah427
 *
 * Created on 27 ?????, 2024, 11:41 ?
 */

#ifndef ECU_DCMOTOR_H
#define	ECU_DCMOTOR_H

/* SECTION: Include */
#include "../../MCAL/GPIO/hal_gpio.h"

/* SECTION: Macro Declarations */

/* SECTION: Macro Function Declarations */
#define DC_MOTOR_OFF_STATUS     0
#define DC_MOTOR_ON_STATUS      1

/* SECTION: Data Type Declarations */
typedef struct{
    uint8 Port: 4;
    uint8 Pin: 3;
    uint8 Status: 1;
}dc_motor;

typedef struct{
    dc_motor pin_config_dc_motor[2];
}dc_motor_t;

/* SECTION: Interface Function Declarations */

Std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor);




#endif	/* ECU_DCMOTOR_H */

