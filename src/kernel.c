#define COL 25
#define ROW 80
#define SCREEN_SIZE COL * ROW

#define GREEN 0x07
#define RED 
#define WHITE 0xF

int current_lock = 0;
char *vidptr = (char *)0xb8000;

void clear_screen(void)
{
    int i = 0;
    while(i < SCREEN_SIZE) 
    {
        vidptr[i++] = ' ';
        vidptr[i++] = GREEN;
    }
}



void kprint(const char *str) 
{
    int i = 0;
    while(i < SCREEN_SIZE) 
    {
        vidptr[current_lock++] = str[i++];
        vidptr[current_lock++] = GREEN;
    }
}

void kmain(void) 
{
    clear_screen();
    kprint("hello world");
}



