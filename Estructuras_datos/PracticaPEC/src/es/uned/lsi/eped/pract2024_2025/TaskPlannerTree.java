package es.uned.lsi.eped.pract2024_2025;


import es.uned.lsi.eped.DataStructures.IteratorIF;
import es.uned.lsi.eped.DataStructures.Queue;
import es.uned.lsi.eped.DataStructures.QueueIF;
import es.uned.lsi.eped.DataStructures.BSTreeIF.IteratorModes;
import es.uned.lsi.eped.DataStructures.BSTreeIF;
import es.uned.lsi.eped.DataStructures.BSTree;

public class TaskPlannerTree implements TaskPlannerIF{

	/* Declaración de atributos para almacenar la información del planificador de tareas */

	/* Estructura que almacena las tareas pasadas */
	protected QueueIF<TaskIF> pastTasks;
	/* La estructura que almacena las tareas futuras debe ser un BSTree */
	protected BSTreeIF<TaskIF> futureTasks;

	/* Constructor */
	TaskPlannerTree(){
		pastTasks = new Queue<>();
		futureTasks = new BSTree<>();	//Instanciamos tipo Lista para poder insertar en cualquier posición
	}

	/* Añade una nueva tarea
	 * @param text: descripción de la tarea
	 * @param date: fecha en la que la tarea debe completarse
	 */
	public void add(String text,int date) {
		TaskIF nuevaTarea = new Task(false, text, date); //creamos nueva tarea para agregar
		futureTasks.add(nuevaTarea);
	}

	/* Elimina una tarea
	 * @param date: fecha de la tarea que se debe eliminar
	 */
	public void delete(int date) {
		// Se recorre la lista hasta encontrar la Tarea para eliminar
		IteratorIF<TaskIF> it = futureTasks.iterator(IteratorModes.DIRECTORDER);
		TaskIF tarea;
		while(it.hasNext()) {
			tarea = it.getNext();
			if (tarea.getDate() == date) {
				futureTasks.remove(tarea);
				break;
			}
		}
	}

	/* Reprograma una tarea
	 * @param origDate: fecha actual de la tarea
	 * @param newDate: nueva fecha de la tarea
	 */
	public void move(int origDate,int newDate) {
		//primero buscar el elemento que queremos mover
		IteratorIF<TaskIF> it = futureTasks.iterator(IteratorModes.DIRECTORDER); //usamos el iterador para buscar el elemento
		
		TaskIF tareaMovida = null;
		while(it.hasNext()) {
			tareaMovida = it.getNext();
			if (tareaMovida.getDate() == origDate) {
				break;
			}
		}

		this.add(tareaMovida.getText(), newDate);	//creamos un nuevo elemento en la nueva posicion
		this.delete(origDate);	//eliminamos el elemento de la posicion antigua
	}

	/* Ejecuta la próxima tarea:
	 * la mete en el histórico marcándola como completada
	 */
	public void execute() {
		//eliminar primera tarea de futureTasks
		//Añadir esta tarea en el historico pastTasks y marcarla como completada
		IteratorIF<TaskIF> it = futureTasks.iterator(IteratorModes.DIRECTORDER);	//obtiene el primer elemento
		TaskIF tarea;
		tarea = it.getNext();
		System.out.println("Primer elemento es:  " + tarea.getText());
		this.delete(tarea.getDate());//elimina el primer elemento
		tarea.setCompleted(); //marcamos la tarea como completada
		pastTasks.enqueue(tarea); //añade el elemento al histórico
	}

	/* Descarta la próxima tarea:
	 * la mete en el histórico marcándola como no completada
	 */
	public void discard() {
		//eliminar primera tarea de futureTasks
		//Añadir esta tarea en el historico pastTasks y marcarla como completada
		IteratorIF<TaskIF> it = futureTasks.iterator(IteratorModes.DIRECTORDER);	//obtiene el primer elemento
		TaskIF tarea;
		tarea = it.getNext();
		System.out.println("Primer elemento es:  " + tarea.getText());
		this.delete(tarea.getDate());//elimina el primer elemento
		//tarea.setCompleted(); //NO marcamos la tarea como completada
		pastTasks.enqueue(tarea); //añade el elemento al histórico
	}

	/* Devuelve un iterador de las tareas futuras */
	public IteratorIF<TaskIF> iteratorFuture() {
		return futureTasks.iterator(IteratorModes.DIRECTORDER); //TODO
	}

	/* Devuelve un iterador del histórico de tareas pasadas */
	public IteratorIF<TaskIF> iteratorPast() {
		return pastTasks.iterator();	//TODO
	}
		
}
