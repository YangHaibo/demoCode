/**************************************************************************
*
* Module:       localtest2.c
*
* Description:  Test code to test Local view and Watch view.
*
* Project:      Wind River Demonstration Program
*
*               Copyright (c) 2003 Wind River Systems, Inc.
*
****************************************************************************/
/*
 * Extern
 */

extern void stackTest();

/*
 *  General Definitions
 */


typedef enum {sunday, monday, tuesday, wednesday, thursday, friday, saturday} day;

typedef struct {        
	  long long_integer;
	  short short_integer;
	  int integer_array[4];
	  char *string_pointer;
	  float float_var;
	} STRUCT_TYPE1;

typedef enum {red, yellow, blue} color_type;

typedef struct {
	  short   a;
	  char    b[4];
	  long    c;
	  day d1;
	} STRUCT_TYPE2;
	
typedef union {        
	  long long_integer;
	  short short_integer;
	  int integer_array[4];
	  char *string_pointer;
	  float float_var;
	} UNION_TYPE1;
	

typedef struct {
	  int 	int_var20;
	  float float_var20;
	  char *string_pointer20;
  
	  UNION_TYPE1 u1;
	} INNER_STRUCT_TYPE20;

typedef struct {
	  int 	int_var19;
	  float float_var19;
	  char *string_pointer19;
	  INNER_STRUCT_TYPE20 s20; 
	} INNER_STRUCT_TYPE19;

typedef struct {
	  int 	int_var18;
	  float float_var18;
	  char *string_pointer18;
	  INNER_STRUCT_TYPE19 s19; 
	} INNER_STRUCT_TYPE18;

typedef struct {
	  int 	int_var17;
	  float float_var17;
	  char *string_pointer17;
	  INNER_STRUCT_TYPE18 s18; 
	} INNER_STRUCT_TYPE17;

typedef struct {
	  int 	int_var16;
	  float float_var16;
	  char *string_pointer16;
	  INNER_STRUCT_TYPE17 s17; 
	} INNER_STRUCT_TYPE16;

typedef struct {
	  int 	int_var15;
	  float float_var15;
	  char *string_pointer15;
	  INNER_STRUCT_TYPE16 s16; 
	} INNER_STRUCT_TYPE15;

typedef struct {
	  int 	int_var14;
	  float float_var14;
	  char *string_pointer14;
	  INNER_STRUCT_TYPE15 s15; 
	} INNER_STRUCT_TYPE14;

typedef struct {
	  int 	int_var13;
	  float float_var13;
	  char *string_pointer13;
	  INNER_STRUCT_TYPE14 s14; 
	} INNER_STRUCT_TYPE13;

typedef struct {
	  int 	int_var12;
	  float float_var12;
	  char *string_pointer12;
	  INNER_STRUCT_TYPE13 s13; 
	} INNER_STRUCT_TYPE12;

typedef struct {
	  int 	int_var11;
	  float float_var11;
	  char *string_pointer11;
	  INNER_STRUCT_TYPE12 s12; 
	} INNER_STRUCT_TYPE11;

typedef struct {
	  int 	int_var10;
	  float float_var10;
	  char *string_pointer10;
	  INNER_STRUCT_TYPE11 s11; 
	} INNER_STRUCT_TYPE10;

typedef struct {
	  int 	int_var9;
	  float float_var9;
	  char *string_pointer9;
	  INNER_STRUCT_TYPE10 s10; 
	} INNER_STRUCT_TYPE9;

typedef struct {
	  int 	int_var8;
	  float float_var8;
	  char *string_pointer8;
	  INNER_STRUCT_TYPE9 s9; 
	} INNER_STRUCT_TYPE8;

typedef struct {
	  int 	int_var7;
	  float float_var7;
	  char *string_pointer7;
	  INNER_STRUCT_TYPE8 s8; 
	} INNER_STRUCT_TYPE7;

typedef struct {
	  int 	int_var6;
	  float float_var6;
	  char *string_pointer6;
	  INNER_STRUCT_TYPE7 s7; 
	} INNER_STRUCT_TYPE6;

typedef struct {
	  int 	int_var5;
	  float float_var5;
	  char *string_pointer5;
	  INNER_STRUCT_TYPE6 s6; 
	} INNER_STRUCT_TYPE5;

typedef struct {
	  int 	int_var4;
	  float float_var4;
	  char *string_pointer4;
	  INNER_STRUCT_TYPE5 s5; 
	} INNER_STRUCT_TYPE4;

typedef struct {
	  int 	int_var3;
	  float float_var3;
	  char *string_pointer3;
	  INNER_STRUCT_TYPE4 s4; 
	} INNER_STRUCT_TYPE3;

typedef struct {
	  int 	int_var2;
	  float float_var2;
	  char *string_pointer2;
	  INNER_STRUCT_TYPE3 s3; 
	} INNER_STRUCT_TYPE2;

typedef struct {
	  int 	int_var1;
	  float float_var1;
	  char *string_pointer1;
	  INNER_STRUCT_TYPE2 s2; 
	} INNER_STRUCT_TYPE1;

	
/************************************************************************
* Function:    LocalViewTest1()
* Description: To test local view.
*************************************************************************/

void LocalViewTest1()
{
	int var1, var2, var3, var4, var5, var6, var7, var8, var9, var10;
	int var11, var12, var13, var14, var15, var16, var17, var18, var19, var20;
	int var21, var22, var23, var24, var25, var26, var27, var28, var29, var30;
	int var31, var32, var33, var34, var35, var36, var37, var38, var39, var40;
	int var41, var42, var43, var44, var45, var46, var47, var48, var49, var50;
	int var51, var52, var53, var54, var55, var56, var57, var58, var59, var60;
	int var61, var62, var63, var64, var65, var66, var67, var68, var69, var70;
	int var71, var72, var73, var74, var75, var76, var77, var78, var79, var80;
	int var81, var82, var83, var84, var85, var86, var87, var88, var89, var90;
	int var91, var92, var93, var94, var95, var96, var97, var98, var99, var100;
	
	static staticVar;
	
	staticVar++;

	var1 = 1;
	var2 = 2;
	var3 = 3;
	var4 = 4;
	var5 = 5;
	var6 = 6;
	var7 = 7;
	var8 = 8;
	var9 = 9;
	var10 = 10;
	var11 = 11;
	var12 = 12;
	var13 = 13;
	var14 = 14;
	var15 = 15;
	var16 = 16;
	var17 = 17;
	var18 = 18;
	var19 = 19;
	var20 = 20;
	var21 = 21;
	var22 = 22;
	var23 = 23;
	var24 = 24;
	var25 = 25;
	var26 = 26;
	var27 = 27;
	var28 = 28;
	var29 = 29;
	var30 = 30;
	var31 = 31;
	var32 = 32;
	var33 = 33;
	var34 = 34;
	var35 = 35;
	var36 = 36;
	var37 = 37;
	var38 = 38;
	var39 = 39;
	var40 = 40;
	var41 = 41;
	var42 = 42;
	var43 = 43;
	var44 = 44;
	var45 = 45;
	var46 = 46;
	var47 = 47;
	var48 = 48;
	var49 = 49;
	var50 = 50;
	var51 = 51;
	var52 = 52;
	var53 = 53;
	var54 = 54;
	var55 = 55;
	var56 = 56;
	var57 = 57;
	var58 = 58;
	var59 = 59;
	var60 = 60;
	var61 = 61;
	var62 = 62;
	var63 = 63;
	var64 = 64;
	var65 = 65;
	var66 = 66;
	var67 = 67;
	var68 = 68;
	var69 = 69;
	var70 = 70;
	var71 = 71;
	var72 = 72;
	var73 = 73;
	var74 = 74;
	var75 = 75;
	var76 = 76;
	var77 = 77;
	var78 = 78;
	var79 = 79;
	var80 = 80;
	var81 = 81;
	var82 = 82;
	var83 = 83;
	var84 = 84;
	var85 = 85;
	var86 = 86;
	var87 = 87;
	var88 = 88;
	var89 = 89;
	var90 = 90;
	var91 = 91;
	var92 = 92;
	var93 = 93;
	var94 = 94;
	var95 = 95;
	var96 = 96;
	var97 = 97;
	var98 = 98;
	var99 = 99;
	var100 = 100;

}

/************************************************************************
* Function:    LocalViewTest2()
* Description: To test local view.
*************************************************************************/

void LocalViewTest2()
{
	int intVar1, intVar2, intVar3, intVar4, intVar5, intVar6, intVar7, intVar8, intVar9, intVar10;
	int intVar11, intVar12, intVar13, intVar14, intVar15, intVar16, intVar17, intVar18, intVar19, intVar20;
	float floatVar1, floatVar2, floatVar3, floatVar4, floatVar5, floatVar6, floatVar7, floatVar8, floatVar9, floatVar10;
	float floatVar11, floatVar12, floatVar13, floatVar14, floatVar15, floatVar16, floatVar17, floatVar18, floatVar19, floatVar20;

	intVar1 = 1;
	intVar2 = 2;
	intVar3 = 3;
	intVar4 = 4;
	intVar5 = 5;
	intVar6 = 6;
	intVar7 = 7;
	intVar8 = 8;
	intVar9 = 9;
	intVar10 = 10;
	intVar11 = 11;
	intVar12 = 12;
	intVar13 = 13;
	intVar14 = 14;
	intVar15 = 15;
	intVar16 = 16;
	intVar17 = 17;
	intVar18 = 18;
	intVar19 = 19;
	intVar20 = 20;

	floatVar1 = 1.1;
	floatVar2 = 2.2;
	floatVar3 = 3.3;
	floatVar4 = 4.4;
	floatVar5 = 5.5;
	floatVar6 = 6.6;
	floatVar7 = 7.7;
	floatVar8 = 8.8;
	floatVar9 = 9.9;
	floatVar10 = 10.10;
	floatVar11 = 11.11;
	floatVar12 = 12.12;
	floatVar13 = 13.13;
	floatVar14 = 14.14;
	floatVar15 = 15.15;
	floatVar16 = 16.16;
	floatVar17 = 17.17;
	floatVar18 = 18.18;
	floatVar19 = 19.19;
	floatVar20 = 20.20;

}

/************************************************************************
* Function:    LocalViewTest3()
* Description: To test the union in Local view.
*************************************************************************/

void LocalViewTest3()
{
	UNION_TYPE1 u[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		u[i].long_integer = i;
		u[i].short_integer = i+100;
		u[i].integer_array[0] = i + 10;
		u[i].integer_array[1] = i + 20;
		u[i].integer_array[2] = i + 30;
		u[i].integer_array[3] = i + 40;
		u[i].string_pointer = "Wind River's WindPower Product Family";
		u[i].float_var = i + 100.10;
	}
}


/************************************************************************
* Function:    LocalViewTest4()
* Description: To test local view.
*************************************************************************/

void LocalViewTest4()
{
	int i;

	int int_array1[5];
	int int_array2[5];
	int int_array3[5];
	int int_array4[5];
	int int_array5[5];

	float float_array1[5];
	float float_array2[5];
	float float_array3[5];
	float float_array4[5];
	float float_array5[5];
	
	UNION_TYPE1 union_array[5];
	day enum_array[5];
	STRUCT_TYPE1 struct_array1[5];
	STRUCT_TYPE2 struct_array2[5];

	char char_array1[5];

	long long_array1[5];
	long long_array2[5];
	long long_array3[5];
	long long_array4[5];
	long long_array5[5];
	
	for (i = 0; i < 5; i++)
	{
		int_array1[i] = i;
		int_array2[i] = i * 2;
		int_array3[i] = i * 3;
		int_array4[i] = i * 4;
		int_array5[i] = i * 5;
		
		float_array1[i] = i + 0.1;
		float_array2[i] = i + 0.2;
		float_array3[i] = i + 0.3;
		float_array4[i] = i + 0.4;
		float_array5[i] = i + 0.5;
		
		union_array[i].long_integer = i;
		union_array[i].short_integer = i + 10;
		union_array[i].integer_array[0] = i + 100;
		union_array[i].integer_array[1] = i + 200;
		union_array[i].integer_array[2] = i + 300;
		union_array[i].integer_array[3] = i + 400;
		union_array[i].string_pointer = "Wind River's WindPower Product Family";
		union_array[i].float_var = i + 0.10;
		
		enum_array[i] = i;
		
		struct_array1[i].long_integer = i + 1000;
		struct_array1[i].short_integer = i + 2000;
		struct_array1[i].integer_array[0] = i + 10;
		struct_array1[i].integer_array[1] = i + 10;
		struct_array1[i].integer_array[2] = i + 10;
		struct_array1[i].integer_array[3] = i + 10;
		struct_array1[i].string_pointer = "Wind River's WindPower Product Family";
		struct_array1[i].float_var = i + 10.10;
		
		struct_array2[i].a = i + 10;
		struct_array2[i].b[0] = 'W';
		struct_array2[i].b[1] = 'R';
		struct_array2[i].b[2] = 'S';
		struct_array2[i].b[3] = '\0';
		struct_array2[i].c = i + 100;
		struct_array2[i].d1 = sunday;
		
		char_array1[i] = 'a' + i;
		
		long_array1[i] = i * 1000;
		long_array2[i] = i * 2000;
		long_array3[i] = i * 3000;
		long_array4[i] = i * 4000;
		long_array5[i] = i * 5000;
		
	}
	
}

/************************************************************************
* Function:    LocalViewTest5()
* Description: To test local view.
*************************************************************************/

void LocalViewTest5()
{
	INNER_STRUCT_TYPE1 s1;
	s1.int_var1 = 1;
	s1.float_var1 = 1.1;
	s1.string_pointer1 = "One";
	
	s1.s2.int_var2 = 2;
	s1.s2.float_var2 = 2.2;
	s1.s2.string_pointer2 = "Two";
	
	s1.s2.s3.int_var3 = 3;
	s1.s2.s3.float_var3 = 3.3;
	s1.s2.s3.string_pointer3 = "Three";
	
	s1.s2.s3.s4.int_var4 = 4;
	s1.s2.s3.s4.float_var4 = 4.4;
	s1.s2.s3.s4.string_pointer4 = "Four";
	
	s1.s2.s3.s4.s5.int_var5 = 5;
	s1.s2.s3.s4.s5.float_var5 = 5.5;
	s1.s2.s3.s4.s5.string_pointer5 = "Five";
	
	s1.s2.s3.s4.s5.s6.int_var6 = 6;
	s1.s2.s3.s4.s5.s6.float_var6 = 6.6;
	s1.s2.s3.s4.s5.s6.string_pointer6 = "Six";
	
	s1.s2.s3.s4.s5.s6.s7.int_var7 = 7;
	s1.s2.s3.s4.s5.s6.s7.float_var7 = 7.7;
	s1.s2.s3.s4.s5.s6.s7.string_pointer7 = "Seven";
	
	s1.s2.s3.s4.s5.s6.s7.s8.int_var8 = 8;
	s1.s2.s3.s4.s5.s6.s7.s8.float_var8 = 8.8;
	s1.s2.s3.s4.s5.s6.s7.s8.string_pointer8 = "Eight";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.int_var9 = 9;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.float_var9 = 9.9;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.string_pointer9 = "Nine";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.int_var10 = 10;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.float_var10 = 10.10;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.string_pointer10 = "Ten";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.int_var11 = 11;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.float_var11 = 11.11;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.string_pointer11 = "Eleven";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.int_var12 = 12;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.float_var12 = 12.12;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.string_pointer12 = "Twelve";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.int_var13 = 13;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.float_var13 = 13.13;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.string_pointer13 = "Thirteen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.int_var14 = 14;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.float_var14 = 14.14;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.string_pointer14 = "Fourteen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.int_var15 = 15;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.float_var15 = 15.15;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.string_pointer15 = "Fifteen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.int_var16 = 16;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.float_var16 = 16.16;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.string_pointer16 = "Sixteen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.int_var17 = 17;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.float_var17 = 17.17;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.string_pointer17 = "Seventeen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.int_var18 = 18;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.float_var18 = 18.18;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.string_pointer18 = "Eighteen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.int_var19 = 19;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.float_var19 = 19.19;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.string_pointer19 = "Nineteen";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.int_var20 = 20;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.float_var20 = 20.20;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.string_pointer20 = "Twenty";
	
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.long_integer = 100;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.short_integer = 200;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.integer_array[0] = 300;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.integer_array[1] = 400;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.integer_array[2] = 500;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.integer_array[3] = 600;
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.string_pointer = "Wind River's WindPower Product Family";
	s1.s2.s3.s4.s5.s6.s7.s8.s9.s10.s11.s12.s13.s14.s15.s16.s17.s18.s19.s20.u1.float_var = 100.1;
	
}

/************************************************************************
* Function:    LocalViewTest6()
* Description: To test local view.
*************************************************************************/

void LocalViewTest6()
{
	stackTest();
}


/************************************************************************
* Function:    LocalViewTest7()
* Description: To test local view test7 and test9.
*************************************************************************/

void LocalViewTest7()
{
	int i;
	
	int var1;
	float var2;
	
	for (i = 0; i < 50; i++)
	{
		var1 = 100 * i;
		var2 = 100.001 + i;
	}
}

/************************************************************************
* Function:    LocalViewTest8()
* Description: To test local view.
*************************************************************************/

void LocalViewTest8()
{
	int i = 0;
	
	int intVar1 = 1;
	int intVar2 = 2;
	int intVar3 = 3;
	int intVar4 = 4;
	int intVar5 = 5;
	int intVar6 = 6;
	int intVar7 = 7;
	int intVar8 = 8;
	int intVar9 = 9;
	int intVar10 = 10;
	int intVar11 = 11;
	int intVar12 = 12;
	int intVar13 = 13;
	int intVar14 = 14;
	int intVar15 = 15;
	int intVar16 = 16;
	int intVar17 = 17;
	int intVar18 = 18;
	int intVar19 = 19;
	int intVar20 = 20;

	float floatVar1 = 1.1;
	float floatVar2 = 2.2;
	float floatVar3 = 3.3;
	float floatVar4 = 4.4;
	float floatVar5 = 5.5;
	float floatVar6 = 6.6;
	float floatVar7 = 7.7;
	float floatVar8 = 8.8;
	float floatVar9 = 9.9;
	float floatVar10 = 10.10;
	float floatVar11 = 11.11;
	float floatVar12 = 12.12;
	float floatVar13 = 13.13;
	float floatVar14 = 14.14;
	float floatVar15 = 15.15;
	float floatVar16 = 16.16;
	float floatVar17 = 17.17;
	float floatVar18 = 18.18;
	float floatVar19 = 19.19;
	float floatVar20 = 20.20;

	intVar1 = intVar2;
	intVar2 = intVar3;
	intVar3 = intVar4;
	intVar4 = intVar5;
	intVar5 = intVar6;
	intVar6 = intVar7;
	intVar7 = intVar8;
	intVar8 = intVar9;
	intVar9 = intVar10;
	intVar10 = intVar11;
	intVar11 = intVar12;
	intVar12 = intVar13;
	intVar13 = intVar14;
	intVar14 = intVar15;
	intVar15 = intVar16;
	intVar16 = intVar17;
	intVar17 = intVar18;
	intVar18 = intVar19;
	intVar19 = intVar20;
	intVar20 = intVar1;

	floatVar1 = floatVar2;
	floatVar2 = floatVar3;
	floatVar3 = floatVar4;
	floatVar4 = floatVar5;
	floatVar5 = floatVar6;
	floatVar6 = floatVar7;
	floatVar7 = floatVar8;
	floatVar8 = floatVar9;
	floatVar9 = floatVar10;
	floatVar10 = floatVar11;
	floatVar11 = floatVar12;
	floatVar12 = floatVar13;
	floatVar13 = floatVar14;
	floatVar14 = floatVar15;
	floatVar15 = floatVar16;
	floatVar16 = floatVar17;
	floatVar17 = floatVar18;
	floatVar18 = floatVar19;
	floatVar19 = floatVar20;
	floatVar20 = floatVar1;

	for (i = 0; i<=100; i++)
	{
		intVar1 = i;
		intVar2 = i;
		intVar3 = i;
		intVar4 = i;
		intVar5 = i;
		intVar6 = i;
		intVar7 = i;
		intVar8 = i;
		intVar9 = i;
		intVar10 = i;
		intVar11 = i;
		intVar12 = i;
		intVar13 = i;
		intVar14 = i;
		intVar15 = i;
		intVar16 = i;
		intVar17 = i;
		intVar18 = i;
		intVar19 = i;
		intVar20 = i;

		floatVar1 = i + 0.1;
		floatVar2 = i + 0.1;
		floatVar3 = i + 0.1;
		floatVar4 = i + 0.1;
		floatVar5 = i + 0.1;
		floatVar6 = i + 0.1;
		floatVar7 = i + 0.1;
		floatVar8 = i + 0.1;
		floatVar9 = i + 0.1;
		floatVar10 = i + 0.1;
		floatVar11 = i + 0.1;
		floatVar12 = i + 0.1;
		floatVar13 = i + 0.1;
		floatVar14 = i + 0.1;
		floatVar15 = i + 0.1;
		floatVar16 = i + 0.1;
		floatVar17 = i + 0.1;
		floatVar18 = i + 0.1;
		floatVar19 = i + 0.1;
		floatVar20 = i + 0.1;
	}
		
}

