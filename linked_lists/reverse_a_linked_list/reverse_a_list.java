import java.util.Random;

public class reverse_a_list {
	
	public static void main(String args[]){
		Random generate = new Random();
		
		linked_list_head head = new linked_list_head( new link_list());
		link_list new_node = new link_list( generate.nextInt(100));
		
		System.out.println("initialize head: " + head);
		System.out.println("initialize add node: " + new_node);
		
		insert( new_node, head);
		
		System.out.println("head after insertion: " + head);
		
		System.out.println("----------------------");
		
		System.out.println("generating random linked list");
		//java forcibly quits runtime after 1050 creations of link_list
		for(int i=0;i<10;i++){
			insert( new link_list( generate.nextInt(100)), head);
		}
		
		System.out.println(head);
		
		System.out.println("reversing linked list");
		reverse( head.head.getNext(), head.head, head);
		
		System.out.println( head);
	}
	
	public static void insert( link_list node, linked_list_head start){
		node.setNext( start.head);
		start.head = node;
	}
	
	public static void reverse( link_list point, link_list prev, linked_list_head start){
		if( point.getNext() == null){
			point.setNext( prev);
			prev.setNext( null);
			start.head = point;
			return;
		}
		
		reverse( point.getNext(), prev.getNext(), start);
		point.setNext( prev);
		prev.setNext( null);
		return;		
	}
}