
public class BST{

	private Node root;
	
	public void add_a_node(String name){
	
		boolean addToLeft = false;
		Node newNode = new Node(name);
		if(root == null){
			
			root = newNode;
		}
		else{
			Node temp = root;
			while(true){
				
				if(name.equals(temp.name)){
					
					System.out.print("Duplicate name cannot be added.");
					return;
				}
				
				else if(name.compareTo(temp.name) > 0){
					if(temp.right != null){
						temp = temp.right;
						addToLeft = false;
					}
					else{
						break;
					}
					
				}

				else if(name.compareTo(temp.name) < 0){
					
					if(temp.left != null){
						temp = temp.left;
						addToLeft = true;
					}
					else{
						break;
					}
				}

			
			}
	
			if(addToLeft == true){
				temp.left = newNode;
			}
			else{
				temp.right = newNode;
			}
				
			
		}
	}
	
	public void delete_a_node(){

	}

	public void pre_order(Node root){
	
		Node temp = root;
		if(temp == null){
			
			return;
		}
		System.out.print(temp.name);
		pre_order(temp.left);
		pre_order(temp.right);
	}

	public void post_order(Node root){

		Node temp = root;
		if(temp == null){
			
			return;
		}
		pre_order(temp.left);
		pre_order(temp.right);
		System.out.print(temp.name);
	}
	
	public void in_order(Node root){

		Node temp = root;
		if(temp == null){
			
			return;
		}
		pre_order(temp.left);
		System.out.print(temp.name);
		pre_order(temp.right);
	}


	public static void main(String[] args){

		BST tree = new BST();
		tree.add_a_node("Puneet");
		tree.add_a_node("Jyoti");
		tree.add_a_node("Kamran");
		tree.add_a_node("Pawan");
		tree.add_a_node("Ruman");
		tree.post_order(tree.root);			
	}
}
