public class linked_list_head{
	public link_list head;
	
	public linked_list_head( link_list node){
		this.head = node;
	}
	
	public String toString(){
		return this.head.toString();
	}
}