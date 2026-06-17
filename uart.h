#define IN1  1<<21
#define IN2  1<<22
#define BUZZ 1<<23

void txd(unsigned char);
void uart_str(unsigned char*);
void uart_init(void);
void task(float);
void uart_int(int);

int sms = 0;

void task(float value)
{
    if(sms==0)
    {
        uart_str("AT\r\n");
        delay_ms(500);

        uart_str("AT+CPIN?\r\n");
        delay_ms(500);

        uart_str("AT+CREG?\r\n");
        delay_ms(500);

        uart_str("AT+CMGF=1\r\n");
        delay_ms(500);

        uart_str("AT+CMGS=\"6380288144\"\r\n");
        delay_ms(500);

        if(value>15)
        {
IOSET0 = IN1;IOCLR0 = IN2; // MOTOR ON
            uart_str("HIGH TEMPERATURE  ");
uart_int(value);
            lcd_cmd(0x94);
            lcd_str("HIGH TEMPERATURE  ");
        }
        else if(value<10)
        {
IOSET0 = BUZZ;    // BUZZER ON
            uart_str("LOW TEMPERATURE :   ");
uart_int(value);
            lcd_cmd(0x94);
            lcd_str("LOW TEMPERATURE   ");
        }

        delay_ms(500);
        txd(26);
        sms = 1;
    }
}

void uart_init(void)
{
IODIR0  |= IN1|IN2|BUZZ;
    PINSEL0 |= 0x05;
    U0LCR    = 0x83;
    U0DLL    = 97;
    U0DLM    = 0;
    U0LCR    = 0x03;
}

void txd(unsigned char data)
{
    while((U0LSR & (1<<5)) == 0);
    U0THR = data;
}

void uart_str(unsigned char *data)
{
    while(*data)
        txd(*data++);
}


void uart_int(int num)
{
    char buf[10];
    int i = 0;

    if(num == 0)
    {
        txd('0');
        return;
    }

    if(num < 0)
    {
        txd('-');
        num = -num;
    }

    while(num > 0)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while(i--)
    {
        txd(buf[i]);
    }
}