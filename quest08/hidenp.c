int hidenp(char *probe, char *target)
{
    while (*probe != '\0')
    {
        while (*probe != *target && *target != '\0')
            ++target;
        if (*target == '\0')
        {
           return 0;
        }
        ++target;
        ++probe;
    }
    return 1;
}
