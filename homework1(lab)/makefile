flags = -Wall -Werror -Wextra -pedantic

	
homework1_4Test: homework1_4.c homework1_4.h
	gcc -c homework1_4.c
	$(flags)
	
homework1Test: homework1.c homework1_4.h
	gcc homework1.c -o homework1_Output 
	$(flags)

homework1_6: homework1_6.c homework1_6.h
	gcc -c homework1_6.c
	$(flags)
	
homework1_6Test: homework1_6_main.c homework1_6.h
	gcc homework1_6_main.c -o homework1_6_Output
	$(flags)