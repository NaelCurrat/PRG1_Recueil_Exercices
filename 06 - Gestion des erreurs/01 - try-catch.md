# try/catch

Indiquer ce que va afficher chacune des séquences d'instructions suivantes : 

**Rappel** Hiérarchie des exceptions

~~~mermaid
graph TD
  exception(Exception)
  
  bad_alloc(Bad Alloc)
  logic_error(Logic Error)
  invalid_argument(Invalid Argument)
  out_of_range(Out of Range)

  runtime_error(Runtime Error)
  overflow_error(Overflow Error)
  range_error(Range Error)

  exception     --> bad_alloc
  exception     --> logic_error
  logic_error   --> invalid_argument
  logic_error   --> out_of_range
  exception     --> runtime_error
  runtime_error --> overflow_error
  runtime_error --> range_error
~~~

1.
~~~cpp
int main() {
   
   try {
      throw 1;
   } catch (int e) {
      cout << "Dans catch (int) : valeur recue = " << e << endl;
      throw 2.0;
   } catch (double e) {
      cout << "Dans catch (double e) : valeur recue = " << e << endl;
   } catch (...) {
      cout << "Dans catch (...)" << endl;
   }
   cout << "Fin du programme" << endl;
   
   return EXIT_SUCCESS;
}


~~~
<details>
Le throw du double 2.o n'est pas catch car il est déclarer dans un catch lui meme. Et non dans un bloc try. 
<summary>Solution</summary>

Dans catch (int) : valeur recue = 1<br>
terminate called after throwing an instance of 'double'<br>
<br> 
This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.

</details>

2.
~~~cpp
int main() {
   try {
      try {
         throw 1;
      } catch (int e) {
         cout << "Dans catch (int) : valeur recue = " << e << endl;
         throw 2.0;
      } catch (...) {
         cout << "Dans catch (...)" << endl;
      }
   } catch (double e) {
      cout << "Dans catch (double) : valeur recue = " << e << endl;
   }
   cout << "Fin du programme" << endl;
   
   return EXIT_SUCCESS;
}


~~~
<details>
Le throw est déclarer à l'intérieur du try le + imbriqué, mais également dans le try le - imbriqués. Le deuxième throw (double) est donc aussi catch.
<summary>Solution</summary>

Dans catch (int) : valeur recue = 1<br>
Dans catch (double) : valeur recue = 2<br>
Fin du programme<br>

</details>

3.	
~~~cpp
void f() {
   throw 'A';
}

int main() {
   try {
      try {
         f();
      } catch (int) {
         cout << "Dans catch (int) 1" << endl;
         throw;
      } catch (...) {
         cout << "Dans catch (...) 1" << endl;
         throw 65;  
      }
   } catch (int&) {
      cout << "Dans catch (int&)" << endl;
   } catch (int) {
      cout << "Dans catch (int) 2" << endl;
   } catch (const int) {
      cout << "Dans catch (const int)" << endl;
   } catch (...) {
      cout << "Dans catch (...) 2" << endl;
   }
   
   cout << "Fin du programme" << endl;
   
   return EXIT_SUCCESS;
}
~~~
<details>
f() throw un char qui est catch par catch(...). Le throw; n'est jamais executer car on ne rentre jamais dans son catch. Et donc le throw 65; est catch par le premier qui lui correspond donc catch(int&)
<summary>Solution</summary>

Dans catch (...) 1<br>
Dans catch (int&)<br>
Fin du programme<br>

</details>

4. 
~~~cpp
void f() {
   throw std::out_of_range("oops");
}

int main() {
   try {
      try {
         f();
      } catch (runtime_error& e) {
         cout << "R : " << e.what() << endl;
         throw;
      } catch (exception e) {
         cout << "E1 : " << e.what() << endl;
         throw;
      }
   } catch (logic_error& e) {
      cout << "L : " << e.what() << endl;
   } catch (exception& e) {
      cout << "E2 : " << e.what() << endl;
   }
   
   cout << "Fin du programme" << endl;
}
~~~

Consultez la documentation de [`std::out_of_range`](https://en.cppreference.com/w/cpp/error/out_of_range)

<details>
le throw oops; est catch par catch(exception). Ensuite, le throw; relance l'objet original donc throw oops; (pour le try externe) qui est catch par catch (logic_error&).
<summary>Solution</summary>
E1 : std::exception<br>
L : oops<br>
Fin du programme<br>
</details>
