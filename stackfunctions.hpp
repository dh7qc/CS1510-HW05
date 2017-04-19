// Dennis Hahn CS1510 1B Homework #5
// stackfunctions.hpp

template <typename T>
bool LLStack<T>::isEmpty() const
{
	if (m_next != NULL)
		return false;
	else 
		return true;
}

template <typename T>
const T& LLStack<T>::top() const throw ( Oops )
{
	try {
		if (m_next != NULL)
			return m_data; 
		else 
			throw Oops("Empty Empty Empty!! ");
	}

	catch(Oops a)
	{
		cout << a.getMsg() << endl;
	}
}

template <typename T>
void LLStack<T>::push(const T& x) // Like insert_front 
{
	LLStack<T> *tmp = new LLStack;
	tmp -> m_data = m_data;
	tmp -> m_next = m_next;
	m_data = x;
	m_next = tmp;
}

template <typename T>
void LLStack<T>::pop()
{
	if (m_next != NULL)
	{
		LLStack<T> *tmp = m_next;
		m_data = m_next -> m_data;
		m_next = tmp -> m_next;
		delete tmp;
	}
}

template <typename T>
void LLStack<T>::clear()
{
	while (m_next != NULL)
		pop();
}

template <typename T>
void LLStack<T>::output()
{
	const LLStack<T>* p = this;
	
	cout << "[ ";

	while (p->m_next != NULL)
	{
		cout << p->m_data << " ";
		p = p->m_next;
	} 
  
	cout << "]" << endl; 
  
	return;
}
