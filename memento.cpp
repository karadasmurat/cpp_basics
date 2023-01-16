#include "functions.h"
#include "patterns.h"
#include <iostream>
#include <stack>

using std::cout;
using std::endl;

// TODO inner class implementation
// Store the copy of the object’s state in a special object called "memento".
class Memento
{
  private:
    // private members accessible only to Originator
    friend class Originator;
    int version;

    // Constructor
    Memento(int v) : version{v}
    {
    }

    int getVersion() const
    {
        return version;
    }
};

// Actual owner of the state.
class Originator
{
    int version = 0;

  public:
    Originator() = default;

    int getVersion() const
    {
        return version;
    }
    void modifyState()
    {
        cout << "Modify state. Version is now " << ++version << endl;
    }

    // Create and return a snapshot
    Memento saveToMemento()
    {
        cout << "Originator: Saving to Memento." << endl;
        return Memento(version);
    }

    // Restore to a previous state represented by the argument.
    void restoreFromMemento(Memento &m)
    {
        version = m.getVersion();
        cout << "Originator: State after restoring from Memento: " << version << endl;
    }
};

/*
A Caretaker would like to perform an operation on the Originator while having the possibility to rollback.
*/
class Caretaker
{
    std::stack<Memento> history;

  public:
    Caretaker() = default;

    // create a memento from originator argument, and add it to the list of mementos.
    void addSnapshot(Originator &o)
    {
        history.push(o.saveToMemento());
    }
    Memento getSnapshot()
    {
        Memento m = history.top();
        history.pop();
        return m;
    }

    // do something that alters state, therefore create a snapshot.
    // calls createSnapshot() on the originator asking the originator to pass it a memento object.
    void doSomething()
    {
        // TODO ?
    }

    Originator undo()
    {
        // TODO ?
    }
};

void memento()
{
    printTitle("Memento Design Pattern");

    Caretaker caretaker;
    // caretaker.doSomething();

    Originator originator;
    cout << "Initialize: " << originator.getVersion() << endl;

    originator.modifyState();
    caretaker.addSnapshot(originator);

    // modify state
    originator.modifyState();
    originator.modifyState();

    // UNDO: restore last state
    Memento prevState = caretaker.getSnapshot();
    originator.restoreFromMemento(prevState);

    cout << "Current state: " << originator.getVersion() << endl;
}
