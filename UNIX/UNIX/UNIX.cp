/*
 *  UNIX.cp
 *  UNIX
 *
 *  Created by 刘明录 on 14-5-10.
 *  Copyright (c) 2014年 刘明录. All rights reserved.
 *
 */

#include <iostream>
#include "UNIX.h"
#include "UNIXPriv.h"

void UNIX::HelloWorld(const char * s)
{
	 UNIXPriv *theObj = new UNIXPriv;
	 theObj->HelloWorldPriv(s);
	 delete theObj;
};

void UNIXPriv::HelloWorldPriv(const char * s) 
{
	std::cout << s << std::endl;
};

