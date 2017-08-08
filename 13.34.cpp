#include <set>
#include <string>
#include <vector>

class Message;

class Folder {
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder &operator=(const Folder&);
	~Folder() { remove_all(); }

private:
	void addMsg(Message *m_ptr) { msgs.insert(m_ptr); }
	void remMsg(Message *m_ptr) { msgs.erase(m_ptr); }
	std::set<Message*> msgs;
	void add_all();
	void remove_all();
};

class Message {
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const std::string &s = "") : content(s) {}
	Message(const Message&);
	Message &operator= (const Message &);
	~Message();
	void save(Folder &f)
	{
		f.addMsg(this);
		folders.insert(&f);
	}
	void remove(Folder &f)
	{
		f.remMsg(this);
		folders.erase(&f);
	}
private:
	std::string content;
	std::set<Folder*> folders;
	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
	void add_all()
	{
		for (auto folder : folders)
			folder->addMsg(this);
	}
	void remove_all()
	{
		for (auto folder : folders)
			folder->remMsg(this);
	}
};

Message::Message(const Message &m) :
	content(m.content), folders(m.folders)
{
	add_all();
}
Message::~Message()
{
	remove_all();
}

Message& Message::operator=(const Message &rhs)
{
	remove_all();
	content = rhs.content;
	folders = rhs.folders;
	add_all();
	return *this;
}


void swap(Message &lhs, Message &rhs)
{
	lhs.remove_all();
	rhs.remove_all();
	using std::swap;
	swap(lhs.content, rhs.content);
	swap(lhs.folders, rhs.folders);
	lhs.add_all();
	rhs.add_all();
}


//Folder
void Folder::add_all()
{
	for (auto m : msgs)
		m->addFldr(this);
}

void Folder::remove_all()
{
	for (auto m : msgs)
		m->remFldr(this);
}



Folder::Folder(const Folder &f) :
	msgs(f.msgs)
{
	add_all();
}

Folder& Folder::operator=(const Folder &rhs)
{
	remove_all();
	msgs = rhs.msgs;
	add_all();
	return *this;
}

