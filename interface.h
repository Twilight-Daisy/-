#pragma once
#include <string>
#include <windows.h>

using namespace std;

void setcolor(int bgcolor, int color);	// ���� ����
void getinitcolor(CONSOLE_SCREEN_BUFFER_INFO& info);	// ���� ���� ����
void resetcolor(CONSOLE_SCREEN_BUFFER_INFO info);	// ����� �������� ����

void print_blank(int num, string T_F = "F");	// num��Ŭ ���� ���
void print_hyphen(int num, string T_F = "F");	// num��ŭ - ���
void newline(string T_F);	// T_F�� ���� �ٸ� �Լ� ������ ���� ����
void check_enter();	// enterŰ �Է� Ȯ��

void gotoxy(int x, int y);	// Ŀ�� ��ġ ����
void getxy(CONSOLE_SCREEN_BUFFER_INFO& info);	// ���� Ŀ�� ��ġ ����
void resetxy(CONSOLE_SCREEN_BUFFER_INFO info);	// ����� Ŀ�� ��ġ�� ����