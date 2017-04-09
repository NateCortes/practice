
public class link_list {

	private int value;
	private link_list next;
	
	public link_list(){
		this.value = 0;
		this.next = null;
	}
	
	public link_list( int val){
		this.value = val;
		this.next = null;
	}
	
	public link_list getNext(){
		return this.next;
	}
	
	public void setNext( link_list node){
		this.next = node;
	}
	
	public boolean hasNext(){
		return (this.next != null);
	}
	
	public String toString( ){
		if(this.next == null){
			return Integer.toString(this.value);
		}
		else{
			return Integer.toString(this.value)+ " " + this.next.toString() + " ";
		}
	}
}
