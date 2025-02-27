/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
//#include <builtins.h>
#include "project.h"
#define _XTAL_FREQ 80000000UL

dc_motor_t dc_motor1 = {
    .pin_config_dc_motor[0].Port = GPIO_PORTC,
    .pin_config_dc_motor[0].Pin = GPIO_PIN0,
    .pin_config_dc_motor[0].Status = DC_MOTOR_OFF_STATUS,
    
    .pin_config_dc_motor[1].Port = GPIO_PORTC,
    .pin_config_dc_motor[1].Pin = GPIO_PIN1,
    .pin_config_dc_motor[1].Status = DC_MOTOR_OFF_STATUS,
};


dc_motor_t dc_motor2 = {
    .pin_config_dc_motor[0].Port = GPIO_PORTC,
    .pin_config_dc_motor[0].Pin = GPIO_PIN2,
    .pin_config_dc_motor[0].Status = DC_MOTOR_OFF_STATUS,
    
    .pin_config_dc_motor[1].Port = GPIO_PORTC,
    .pin_config_dc_motor[1].Pin = GPIO_PIN3,
    .pin_config_dc_motor[1].Status = DC_MOTOR_OFF_STATUS,

};

//button_t high_btn = {
//  .button_pin = {
//    .Direction = GPIO_INPUT,
//    .Port = GPIO_PORTC,
//    .Pin = GPIO_PIN0,
//    .Logic = GPIO_LOW
//  },  
//  .button_active = BUTTON_ACTIVE_HIGH,
//  .button_status = BUTTON_RELEASED
//};
//
//button_t low_btn = {
//  .button_pin = {
//    .Direction = GPIO_INPUT,
//    .Port = GPIO_PORTC,
//    .Pin = GPIO_PIN1,
//    .Logic = GPIO_HIGH
//  },  
//  .button_active = BUTTON_ACTIVE_HIGH,
//  .button_status = BUTTON_RELEASED
//};



void initialization(void);
//void leftToRight(void);
//void rightToLeft(void);

//button_status_t high_btn_status = BUTTON_RELEASED;
//button_status_t low_btn_status = BUTTON_RELEASED;


void main(void) {
    initialization();
    while(1){
        dc_motor_move_right(&dc_motor1);
        dc_motor_move_right(&dc_motor2);
        
        __delay_ms(100);
        dc_motor_stop(&dc_motor1);
        dc_motor_stop(&dc_motor2);
        __delay_ms(20);
        
        dc_motor_move_left(&dc_motor1);
        dc_motor_move_left(&dc_motor2);
        
         __delay_ms(100);
        dc_motor_stop(&dc_motor1);
        dc_motor_stop(&dc_motor2);
        __delay_ms(20);
    }
    
    return;
}

void initialization(void){
    dc_motor_initialize(&dc_motor1);
    dc_motor_initialize(&dc_motor2);

    
}
