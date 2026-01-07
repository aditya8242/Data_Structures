class node
{
	public int data;
	public node next;
	public node prev;

	public node(int no)
	{
		this.data = no;
		this.next = null;
		this.prev = null;
	}
}

class DoublyLL
{
	private node first;
	private int iCount;

	public DoublyLL()
	{
		this.first = null;
		this.iCount = 0;
	}

	void InsertFirst(int no)
	{
		node newn = null;

		newn = new node(no);

		if(this.first == null)
		{
			this.first = newn;
		}
		else
		{
			newn.next = this.first;
			newn.next.prev = newn;
			this.first = newn;
		}

		this.iCount++;
	}
}

class DoublyLinear
{
	public static void main(String A[])
	{
		
	}
}