#include <stdio.h>

int main()
{
    int size, in = 0, out = 0, items = 0;
    int produce, consume, choice;

    printf("Enter the buffer size: ");
    scanf("%d", &size);

    if(size <= 0)
        return 1;

    int buffer[size];

    while(1)
    {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(items == size)
                    printf("Buffer is full\n");
                else
                {
                    printf("Enter the value: ");
                    scanf("%d", &produce);

                    buffer[in] = produce;
                    in = (in+1) % size;
                    items++;
                }
                break;

            case 2:
                if(items == 0)
                    printf("Buffer is empty\n");
                else
                {
                    consume = buffer[out];
                    printf("Consumed item is: %d\n", consume);

                    out = (out+1) % size;
                    items--;
                }
                break;

            case 3:
                return 0;
        }
    }
}
