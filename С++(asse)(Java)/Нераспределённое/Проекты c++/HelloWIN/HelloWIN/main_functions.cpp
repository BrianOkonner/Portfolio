//#include "human.h"
//int func_main()
//{
//	//thread t1(&creature::attacked,&ennemy, hero);
//	//cout << thread::hardware_concurrency();
//	//if (t1.joinable()) t1.join();
//
//	setlocale(0, "");
//	creature hero("Maksim");
//	int temp, temp1;
//	creature ennemy1(1, "ennemy1");
//	creature ennemy2(3, "ennemy2");
//	creature ennemy3(5, "ennemy3");
//	creature ennemy4(8, "ennemy4");
//	creature ennemy5(15, "ennemy5");
//	creature BOSS(40, "BOSS");
//	hero.setstat();
//start:
//	cout << "Прожив 19 лет в счастливом браке с женой, вы никак не ожидали,\n" <<
//		"что она уйдёт от вас. Теперь у вас осталась единственная\n" <<
//		"возможность восстановить справдливость: убить её любовника!";
//	cout << "\nYou have to kill the BOSS:\n";
//	cout << "1: ennemy1\n2: ennemy2\n3: ennemy3\n4: ennemy4\n5: ennemy5\n6: BOSS\n7: help\n8: give up";
//	while (true)
//	{
//		switch (_getch() - '0')
//		{
//
//		case 1:
//		{
//			if (hero.attacked(ennemy1) == true) {}
//			else ennemy1.attacked1(hero);
//			break;
//		}
//		case 2:
//		{
//			if (hero.attacked(ennemy2) == true) {}
//			else ennemy2.attacked1(hero);
//			break;
//		}
//		case 3:
//		{
//			if (hero.attacked(ennemy3) == true) {}
//			else ennemy3.attacked1(hero);
//			break;
//		}
//		case 4:
//		{
//			if (hero.attacked(ennemy4) == true) {}
//			else ennemy4.attacked1(hero);
//			break;
//		}
//		case 5:
//		{
//			if (hero.attacked(ennemy5) == true) {}
//			else ennemy5.attacked1(hero);
//			break;
//		}
//		case 6:
//		{
//			if (hero.attacked(BOSS) == true) {}
//			else BOSS.attacked1(hero);
//			break;
//		}
//		case 7:
//		{
//			system("cls");
//			cout << "1. Remind me the keys\n2. Check your stat\n3. Your character\n4. Help\n";
//			switch (_getch() - '0')
//			{
//			case 1: goto start;
//			case 2: hero.getstat(); break;
//			case 3: character(hero); break;
//			case 4: Help(); break;
//			default:
//				break;
//			}
//			break;
//		}
//		case 8:
//		{
//			cout << "\nYou are giving up. Good bye, looser";
//			system("pause");
//			return 0;
//		}
//		default: break;
//		}
//
//		if (hero.gethp() <= 0)
//		{
//			cout << "\nYou are dead!\n";
//			for (;;) {}
//			system("pause");
//			return 0;
//		}
//	}
//
//	char temp123[] = "hello";
//	return 0;
//}