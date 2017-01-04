#include <iostream>
#include <sstream>
#include <list>

using namespace std;

class EControl
{
	string name;
	bool is_container;
public:
	EControl(const string& name, bool is_container)
		: name(name),
		  is_container(is_container)
	{
	}

	virtual ~EControl()
	{
	}

	string getName() const
	{
		return name;
	}

	bool isContainer() const
	{
		return is_container;
	}

	virtual void print(ostream& out) const
	{
		out << this->getName() << endl;
	}
};

class EContainer : public EControl
{
	list<EControl*> children;
public:
	explicit EContainer(const string& name)
		: EControl(name, true)
	{
	}

	~EContainer()
	{
		for (auto i : children)
		{
			delete i;
		}
	}

	void addChild(EControl* child)
	{
		children.push_back(child);
	}

	void deleteChild(const string& name)
	{
		for (auto i = children.begin(); i != children.end(); ++i)
		{
			if ((*i)->getName() == name)
			{
				auto p = *i;
				children.erase(i);
				delete p;
				return;
			}
			if ((*i)->isContainer())
			{
				auto container = static_cast<EContainer*>(*i);
				container->deleteChild(name);
			}
		}
	}

	EControl* findChild(const string& name) const
	{
		for (auto& child : children)
		{
			if (child->getName() == name)
			{
				return child;
			}
			if (child->isContainer())
			{
				auto container = static_cast<EContainer*>(child);
				auto control = container->findChild(name);
				if (control != nullptr)
				{
					return control;
				}
			}
		}
		return nullptr;
	}

	void print(ostream& out) const override
	{
		out << this->getName() << endl;
		for (auto& child : children)
		{
			child->print(out);
		}
	}
};

class EItem : public EControl
{
public:
	explicit EItem(const string& name)
		: EControl(name, false)
	{
	}
};

class EApp : public EContainer
{
	static EApp instance;
public:
	explicit EApp()
		: EContainer("App")
	{
	}

	static EApp& getInstance()
	{
		return instance;
	}
};

class EWindow : public EContainer
{
public:
	explicit EWindow(const string& name)
		: EContainer(name)
	{
	}
};

class EPanel : public EContainer
{
public:
	explicit EPanel(const string& name)
		: EContainer(name)
	{
	}
};

class EButton : public EItem
{
public:
	explicit EButton(const string& name)
		: EItem(name)
	{
	}
};

class ECheckBox : public EItem
{
public:
	explicit ECheckBox(const string& name)
		: EItem(name)
	{
	}
};

class ELabel : public EItem
{
public:
	explicit ELabel(const string& name)
		: EItem(name)
	{
	}
};

class ETextEdit : public EItem
{
public:
	explicit ETextEdit(const string& name)
		: EItem(name)
	{
	}
};

EApp EApp::instance;

int main()
{
	auto& app = EApp::getInstance();
	int n;

	cin >> n;
	string op, name, pname;
	for (auto i = 0; i < n; ++i)
	{
		cin >> op >> name;
		if (op == "+")
		{
			cin >> pname;
			EContainer* parent;
			if (pname == "App")
			{
				parent = &app;
			}
			else
			{
				parent = static_cast<EContainer*>(app.findChild(pname));
			}
			if (parent != nullptr && parent->isContainer())
			{
				switch (name[0])
				{
				case 'W':
					parent->addChild(new EWindow(name));
					break;
				case 'P':
					parent->addChild(new EPanel(name));
					break;
				case 'B':
					parent->addChild(new EButton(name));
					break;
				case 'C':
					parent->addChild(new ECheckBox(name));
					break;
				case 'L':
					parent->addChild(new ELabel(name));
					break;
				case 'T':
					parent->addChild(new ETextEdit(name));
					break;
				}
			}
		}
		else if (op == "-")
		{
			app.deleteChild(name);
		}
	}

	cin >> n;
	for (auto i = 0; i < n; ++i)
	{
		cin >> name;
		auto element = app.findChild(name);
		if (element != nullptr)
		{
			element->print(cout);
		}
	}

	cin >> n;
	return 0;
}
