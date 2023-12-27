#ifndef GPIO_H
#define GPIO_H

#define GPIO_FUNC_INPUT      0
#define GPIO_FUNC_OUTPUT     1
#define GPIO_FUNC_ALT_FUNC_0 4
#define GPIO_FUNC_ALT_FUNC_1 5
#define GPIO_FUNC_ALT_FUNC_2 6
#define GPIO_FUNC_ALT_FUNC_3 7
#define GPIO_FUNC_ALT_FUNC_4 3
#define GPIO_FUNC_ALT_FUNC_5 2

#define GPIO_PULL_NONE       0
#define GPIO_PULL_UP         1
#define GPIO_PULL_DOWN       2

void gpio_set_func(int gpio_pin, int func);
void gpio_set_pull_state(int gpio_pin, int pull_state);
void gpio_set(int gpio_pin);
void gpio_clear(int gpio_pin);

#endif // GPIO_H