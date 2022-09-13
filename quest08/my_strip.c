char* my_strip(char* param_1)
{

    int count = 0;

    char* result = malloc(strlen(param_1) + 1);

    for(int i = 0; param_1[i] != '\0'; i++)
    {
    
        if(param_1[i] != ' ')
        {
            result[count++] = param_1[i];
        }
        else
        {
            if(i == 0)
                continue;

            else if(param_1[i + 1] == '\0')
                continue;

            else if(param_1[i + 1] == ' ')
                continue;

            else result[count++] = param_1[i];
        }
    }

    result[count] = '\0';
    return result;
}