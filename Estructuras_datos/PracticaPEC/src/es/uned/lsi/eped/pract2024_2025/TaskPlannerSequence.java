package es.uned.lsi.eped.pract2024_2025;

import es.uned.lsi.eped.DataStructures.IteratorIF;
import es.uned.lsi.eped.DataStructures.QueueIF;
import es.uned.lsi.eped.DataStructures.Queue;
import es.uned.lsi.eped.DataStructures.SequenceIF;
import es.uned.lsi.eped.DataStructures.List;
import es.uned.lsi.eped.DataStructures.ListIF;

public class TaskPlannerSequence implements TaskPlannerIF{

	/* Declaración de atributos para almacenar la información del planificador de tareas */
	
	/* Estructura que almacena las tareas pasadas */
	protected QueueIF<TaskIF> pastTasks;	//histórico, usamos Queue (Cola) porque solo queremos meter datos por el final
	/* La estructura que almacena las tareas futuras debe ser una secuencia */
	protected SequenceIF<TaskIF> futureTasks;

	/* Constructor */
	TaskPlannerSequence(){
		pastTasks = new Queue<>();
		futureTasks = new List<>();	//Instanciamos tipo Lista para poder insertar en cualquier posición
	}

	/* Añade una nueva tarea
	 * @param text: descripción de la tarea
	 * @param date: fecha en la que la tarea debe completarse
	 */
	public void add(String text,int date) {
		
		TaskIF nuevaTarea = new Task(false, text, date); //creamos nueva tarea para agregar
		IteratorIF<TaskIF> it = futureTasks.iterator(); //Primero usamos el iterador para buscar la posición en la que insertar por orden ascendente. Luego insertamos
		int pos = 1;
		while(it.hasNext() && it.getNext().compareTo(nuevaTarea) <= 0) pos ++; 	//mientras que la fecha de la tarea sea mas pequeña (antes), se sigue avanzando
		((ListIF<TaskIF>) futureTasks).insert(pos, nuevaTarea);	//insertamos en posicion ordenada
		
		
	}

	/* Elimina una tarea
	 * @param date: fecha de la tarea que se debe eliminar
	 */
	public void delete(int date) {
		
		// Se recorre la lista hasta encontrar la Tarea para eliminar
		IteratorIF<TaskIF> it = futureTasks.iterator();
		int pos = 1;
		while(it.hasNext()) {
			if (it.getNext().getDate() == date) {
				((ListIF<TaskIF>) futureTasks).remove(pos);
				break;
			}else {
				pos++;
			}
		}

	}

	/* Reprograma una tarea
	 * @param origDate: fecha actual de la tarea
	 * @param newDate: nueva fecha de la tarea
	 */
	public void move(int origDate,int newDate) {
		//primero buscar el elemento que queremos mover
		IteratorIF<TaskIF> it = futureTasks.iterator(); //usamos el iterador para buscar el elemento
		int pos = 1;
		while(it.hasNext() && it.getNext().getDate() != origDate) pos ++; 	//mientras que la fecha no sea la de origen, sique buscando
		System.out.println("pos: " + pos);
		TaskIF tareaMovida = ((ListIF<TaskIF>) futureTasks).get(pos);
		this.add(tareaMovida.getText(), newDate);	//creamos un nuevo elemento en la nueva posicion
		this.delete(origDate);	//eliminamos el elemento de la posicion antigua
	}

	/* Ejecuta la próxima tarea:
	 * la mete en el histórico marcándola como completada
	 */
	public void execute() {
		//eliminar primera tarea de futureTasks
		//Añadir esta tarea en el historico pastTasks y marcarla como completada
		TaskIF tarea = ((ListIF<TaskIF>) futureTasks).get(1);	//obtiene el primer elemento
			System.out.println("Primer elemento es:  " + tarea.getText());
		((List<TaskIF>) futureTasks).remove(1);//elimina el primer elemento
		tarea.setCompleted(); //marcamos la tarea como completada
		pastTasks.enqueue(tarea); //añade el elemento al histórico
	}

	/* Descarta la próxima tarea:
	 * la mete en el histórico marcándola como no completada
	 */
	public void discard() {
		//eliminar primera tarea de futureTasks
		//Añadir esta tarea en el historico pastTasks y marcarla como completada
		TaskIF tarea = ((ListIF<TaskIF>) futureTasks).get(1);	//obtiene el primer elemento
		((List<TaskIF>) futureTasks).remove(1);//elimina el primer elemento
		//tarea.setCompleted(); //NO marcamos la tarea como completada
		pastTasks.enqueue(tarea); //añade el elemento al histórico
	}

	/* Devuelve un iterador de las tareas futuras */
	public IteratorIF<TaskIF> iteratorFuture() {
		return futureTasks.iterator();
	}

	/* Devuelve un iterador del histórico de tareas pasadas */
	public IteratorIF<TaskIF> iteratorPast() {
		return pastTasks.iterator();
	}
		
}
