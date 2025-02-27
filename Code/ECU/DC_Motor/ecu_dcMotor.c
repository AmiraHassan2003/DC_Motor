#include "ecu_dcMotor.h"

static void dc_motor_config(pin_config_t *pin_config1, pin_config_t *pin_config2, const dc_motor_t *dc_motor);


Std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == dc_motor) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_config1, pin_config2;
        dc_motor_config(&pin_config1, &pin_config2, dc_motor);
        
        ret = gpio_pin_initialize(&pin_config1);           
        ret &= gpio_pin_initialize(&pin_config2);
    }
    return ret;
}

Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == dc_motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config1, pin_config2;
        dc_motor_config(&pin_config1, &pin_config2, dc_motor);
        
        ret = gpio_pin_write_logic(&pin_config1, GPIO_HIGH);        
        ret &= gpio_pin_write_logic(&pin_config2, GPIO_LOW);
    }
    return ret;
}


Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == dc_motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config1, pin_config2;
        dc_motor_config(&pin_config1, &pin_config2, dc_motor);
        
        ret = gpio_pin_write_logic(&pin_config1, GPIO_LOW);        
        ret &= gpio_pin_write_logic(&pin_config2, GPIO_HIGH);
    }
    return ret;
}

Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == dc_motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config1, pin_config2;
        dc_motor_config(&pin_config1, &pin_config2, dc_motor);
        
        ret = gpio_pin_write_logic(&pin_config1, GPIO_LOW);        
        ret &= gpio_pin_write_logic(&pin_config2, GPIO_LOW);
    }
    return ret;
}

//static void dc_motor_config(pin_config_t *pin_config[2], dc_motor_t *dc_motor)
//{
//    pin_config[0]->Direction = GPIO_OUTPUT;
//    pin_config[0]->Logic = dc_motor[0].pin_config_dc_motor->Status;
//    pin_config[0]->Pin = dc_motor[0].pin_config_dc_motor->Pin;
//    pin_config[0]->Port = dc_motor[0].pin_config_dc_motor->Port;
//    
//    pin_config[1]->Direction = GPIO_OUTPUT;
//    pin_config[1]->Logic = dc_motor[1].pin_config_dc_motor->Status;
//    pin_config[1]->Pin = dc_motor[1].pin_config_dc_motor->Pin;
//    pin_config[1]->Port = dc_motor[1].pin_config_dc_motor->Port;
//    
//}

static void dc_motor_config(pin_config_t *pin_config1, pin_config_t *pin_config2, const dc_motor_t *dc_motor)
{
    pin_config1->Direction = GPIO_OUTPUT;
    pin_config1->Logic = dc_motor->pin_config_dc_motor[0].Status;
    pin_config1->Pin = dc_motor->pin_config_dc_motor[0].Pin;
    pin_config1->Port = dc_motor->pin_config_dc_motor[0].Port;
    
    pin_config2->Direction = GPIO_OUTPUT;
    pin_config2->Logic = dc_motor->pin_config_dc_motor[1].Status;
    pin_config2->Pin = dc_motor->pin_config_dc_motor[1].Pin;
    pin_config2->Port = dc_motor->pin_config_dc_motor[1].Port;
}