#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<string.h>
enum State
{
	NORMAL,            //普通
	FOUND_SLASH,       //找到斜杠/
	C_COMMENT,         //c风格注释
	CPP_COMMENT,       //c++风格注释
	FOUND_ASTERISK,    //找星号*
};
void CommentConvert(FILE *pIn, FILE *pOut)
{

	enum State state = NORMAL;
	char ch, nextch;
	while (1)
	{
		ch = fgetc(pIn);
		if (ch == EOF)
		{
			break;
		}
		switch (state)
		{
		case NORMAL:
			if (ch == '/')
			{
				state = FOUND_SLASH;
			}
			else
			{
				fputc(ch, pOut);
			}
			break;
		case FOUND_SLASH:
			if (ch == '*')
			{
				fprintf(pOut, "//");
				state = C_COMMENT;
			}
			else if (ch == '/')
			{
				fprintf(pOut, "//");
				state = CPP_COMMENT;
			}
			else
			{
				fputc('/', pOut);
				fputc(ch, pOut);
				state = NORMAL;
			}
			break;
		case C_COMMENT:
			if (ch == '*')
			{
				state = FOUND_ASTERISK;
			}
			else
			{
				fputc(ch, pOut);
				if (ch == '\n')
				{
					fprintf(pOut, "//");
				}
			}
			break;
		case CPP_COMMENT:
			if (ch == '\n')
			{
				fputc(ch, pOut);
				state = NORMAL;
			}
			else
			{
				fputc(ch, pOut);
			}
			break;
		case FOUND_ASTERISK:
			if (ch == '/')
			{
				nextch = fgetc(pIn);
				if (nextch != '\n')
				{
					fputc('\n', pOut);
				}
				ungetc(nextch, pIn);
				state = NORMAL;
			}
			else if (ch == '*')
			{
				fputc('*', pOut);
				state = FOUND_ASTERISK;
			}
			else
			{
				fputc('*', pOut);
				fputc(ch, pOut);
				state = C_COMMENT;
			}
			break;
		}
		const char *messages[] = {
			"普通",
			"找到斜杠了",
			"c风格注释",
			"c++风格注释",
			"找到*"
		};
		printf("当前字符：%c,当前状态是：%s\n", ch, messages[state]);
	}
}
int main()
{
	const char* INPUT = "input.c";
	const char* OUTPUT = "output.c";
	FILE *pIn = fopen(INPUT,"r");
	assert(pIn != NULL);
	FILE *pOut = fopen(OUTPUT, "w");
	assert(pOut != NULL);
	CommentConvert(pIn, pOut);
	fclose(pOut);	// 后打开的先关
	fclose(pIn);
	system("pause");
	return 0;
}
