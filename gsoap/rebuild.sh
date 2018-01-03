#!/bin/bash

mv makefile myclient.cpp myserver.cpp add.h rebuild.sh  curl_test.sh ..
rm *
mv ../makefile ../myclient.cpp ../myserver.cpp ../add.h ../rebuild.sh curl_test.sh .
soapcpp2 -i -c++11 add.h

#make 构建的时候注意添加 -lgsoap++ 动态库
