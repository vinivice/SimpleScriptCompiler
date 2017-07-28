#include<stdio.h>
#include<string.h>

void printUsage(char *arg)
{
        printf("Invalid mode!\n");
        printf("Usage: %s [modes] <script>\n", arg);
        printf("Help: %s h\n", arg);
}

void printHelp()
{
        printf("Mode options:\n");
        printf("l : compile until lexical level <default>\n");
    
}

int main(int argc, char *argv[])
{
    int mode[4] = {1, 0, 0, 0};
    int i;
    char *arg, *scriptName;

    if(argc < 2)
    {
        printUsage(argv[0]);
        return 4;
    } 
    else if(strcmp(argv[1], "h") == 0)
    {
        printHelp();
        return 2;
    }

    for(i = 1; i < argc - 1; i++)
    {
        arg = argv[i];
        if(strlen(arg) > 1)
        {
            printUsage(argv[0]);
            return 3;
        }
       else switch(*arg)
        {
            case 'l':
                mode[0] = 1;
                break;
            default:
                printUsage(argv[0]);
                return 1;
        }
    }
    
    scriptName = argv[argc - 1];

    if(mode[0] == 1)
    {
        printf("Lexical here!!!\n");
    }

return 0;
}


