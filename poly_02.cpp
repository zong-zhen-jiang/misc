#include <cstdio>


class Animal
{
public:

    const char * getName()
    {
        return m_name;
    }

    virtual const char * sound()
    {
        return "";
    }

protected:

    const char * m_name;

    Animal(const char * name) : m_name(name)
    {
    }
};

class Cat : public Animal
{
public:

    Cat() : Animal("Cat")
    {
    }

    virtual const char * sound()
    {
        return "meow";
    }
};

class Dog : public Animal
{
public:

    Dog() : Animal("Dog")
    {
    }

    virtual const char * sound()
    {
        return "woof";
    }
};

class Fox : public Animal
{
public:

    Fox() : Animal("Fox")
    {
    }

    // We do not override sound(), which no one knows!
};


int main()
{
    Cat cat;
    Dog dog;
    Fox fox;

    Animal * animals[] = {&dog, &cat, &fox};
    for (int i = 0; i < 3; i++) {
        const char * sound = animals[i]->sound();
        if (sound[0] != '\0') {
            printf("%s goes %s.\n", animals[i]->getName(), sound);
        } else {
            printf("What (does) the %s say?\n", animals[i]->getName());
        }
    }

    return 0;
}
