//
// Created by yaren on 5/4/16.
//
#ifndef APP2_MEMORY_H
#define APP2_MEMORY_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


class Memory {
public:
    double cpuPcent(void);
    double memoryRequest();
};


#endif //APP2_MEMORY_H
