#include "stdafx.h"
#include "CppUnitTest.h"
#include <LinkedList.h>
#include "Book.h"
#include <Node.h>
#include "Iterator.h"
#include "IterAccess.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorTest
															/****************************
															*Tests composés par Jennifer*
															****************************/
{															
	TEST_CLASS(Iterator_EN)
	{
	public:

		//Test qui doit compiler SANS ÊTRE MODIFIÉ
		
		TEST_METHOD(IteratorShouldCompile)
		{
			LinkedList<Book> l;
			Book* b1 = new Book(1);
			Node<Book> * node = new Node<Book>();
			node->setContent(b1);
			Iterator<Book> iter(node);
			Iterator<Book> iter1;
			Iterator<Book> iter2;

			iter1 = l.begin();
			iter2 = l.end();

			//IterAccess est une classe amie (friend) à Iterator
			//Elle a accès à ses attributs privés pour inspecter le nœud sur lequel l'itérateur est positionné
			//Ceci va vous servir dans vos tests
			IterAccess<Book> ia(iter1);
			ia.getCurrentNode();
			iter1 = l.begin();
			iter1 = l.end();
			++iter1;
			if (iter1 == iter2 || iter1 != iter2)
			{
			}
			Book* test = &iter;
			Assert::IsTrue(true);
		}
		

		//------------------------- Operator ++ -------------------------------------
		TEST_METHOD(TestOperatorIncrement_EmptyList_IsNull)
		{
			LinkedList<Book> l;
			Iterator<Book> iter = l.begin();
			Assert::IsTrue(iter==NULL);

		}
		//----------- Returns True -------------
		TEST_METHOD(TestOperatorIncrement_2NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter = l.begin();
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode()->getContent() == j2);
			delete j1;
			delete j2;
		}
		
		TEST_METHOD(TestOperatorIncrement_5NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode()->getContent() == j4);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorIncrement_10NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode()->getContent() == j8);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//----------- Returns False -------------

		TEST_METHOD(TestOperatorIncrement_2NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter = l.begin();
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsFalse(ia.getCurrentNode()->getContent() == j1);
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorIncrement_5NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsFalse(ia.getCurrentNode()->getContent() == j2);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorIncrement_10NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsFalse(ia.getCurrentNode()->getContent() == j6);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}
		//--------- End list is null ---------
		TEST_METHOD(TestOperatorIncrement_EndList_2Nodes)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode()==NULL);

			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorIncrement_EndList_5Nodes)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode() == NULL);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorIncrement_EndList_10Nodes)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter = l.begin();
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode() == NULL);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//------------------------- Operator == -------------------------------------
		
		//--------- Returns True ---------
		TEST_METHOD(TestOperatorEquals_2NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsTrue(ia1.getCurrentNode() == ia2.getCurrentNode());
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorEquals_5NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsTrue(ia1.getCurrentNode() ==ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorEquals_10NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsTrue(ia1.getCurrentNode() == ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//--------- Returns False ---------
		TEST_METHOD(TestOperatorEquals_2NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsFalse(ia1.getCurrentNode() == ia2.getCurrentNode());
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorEquals_5NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsFalse(ia1.getCurrentNode() == ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorEquals_10NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsFalse(ia1.getCurrentNode() == ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//------------------------- Operator != -------------------------------------

		//--------- Returns False ---------
		TEST_METHOD(TestOperatorNotEquals_2NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsFalse(ia1.getCurrentNode() != ia2.getCurrentNode());
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorNotEquals_5NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsFalse(ia1.getCurrentNode() != ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorNotEquals_10NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsFalse(ia1.getCurrentNode() != ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//--------- Returns True ---------
		TEST_METHOD(TestOperatorNotEquals_2NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsTrue(ia1.getCurrentNode() != ia2.getCurrentNode());
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorNotEquals_5NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsTrue(ia1.getCurrentNode() != ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorNotEquals_10NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter1 = l.begin();
			Iterator<Book> iter2 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			++iter2;
			IterAccess<Book> ia1(iter1);
			IterAccess<Book> ia2(iter2);
			Assert::IsTrue(ia1.getCurrentNode() != ia2.getCurrentNode());
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//------------------------- Operator & -------------------------------------

		TEST_METHOD(TestOperatorAnd_EmptyList_IsNull)
		{
			LinkedList<Book> l;
			Iterator<Book> iter1 = l.begin();
			Assert::IsTrue(&iter1==NULL);
		}

		TEST_METHOD(TestOperatorAnd_2NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter1 = l.begin();
			++iter1;
			IterAccess<Book> ia1(iter1);
			Assert::IsTrue(&iter1==j2);
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorAnd_5NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter1 = l.begin();
			++iter1;
			++iter1;
			Assert::IsTrue(&iter1==j3);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorAnd_10NodesList_ReturnsTrue)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter1 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			Assert::IsTrue(&iter1==j7);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}

		//------- Returns False -----------------------
		TEST_METHOD(TestOperatorAnd_2NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter1 = l.begin();
			++iter1;
			IterAccess<Book> ia1(iter1);
			Assert::IsFalse(&iter1 == j1);
			delete j1;
			delete j2;
		}

		TEST_METHOD(TestOperatorAnd_5NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			Iterator<Book> iter1 = l.begin();
			++iter1;
			++iter1;
			Assert::IsFalse(&iter1 == j2);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
		}

		TEST_METHOD(TestOperatorAnd_10NodesList_ReturnsFalse)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			Book* j3 = new Book(3);
			Book* j4 = new Book(4);
			Book* j5 = new Book(5);
			Book* j6 = new Book(6);
			Book* j7 = new Book(7);
			Book* j8 = new Book(8);
			Book* j9 = new Book(9);
			Book* j10 = new Book(10);
			l.add(j1);
			l.add(j2);
			l.add(j3);
			l.add(j4);
			l.add(j5);
			l.add(j6);
			l.add(j7);
			l.add(j8);
			l.add(j9);
			l.add(j10);
			Iterator<Book> iter1 = l.begin();
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			++iter1;
			Assert::IsFalse(&iter1 == j5);
			delete j1;
			delete j2;
			delete j3;
			delete j4;
			delete j5;
			delete j6;
			delete j7;
			delete j8;
			delete j9;
			delete j10;
		}


	};
}

