#include "FileLogger.h"

int main()
{
    auto path = "file.log";

    FileLogger logger(path);

    {
        double pi = 3.1459265359;

        logger << pi;

        int i = 1234;

        logger << i;

        logger << "A sample message";
    }
}
