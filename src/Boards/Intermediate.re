let one = {
  let values = Hashtbl.create(30);
  /* First row */
  Hashtbl.add(values, "0-1", 2);
  Hashtbl.add(values, "0-3", 6);
  Hashtbl.add(values, "0-5", 8);
  /* Second row */
  Hashtbl.add(values, "1-0", 5);
  Hashtbl.add(values, "1-1", 8);
  Hashtbl.add(values, "1-5", 9);
  Hashtbl.add(values, "1-6", 7);
  /* Third row */
  Hashtbl.add(values, "2-4", 4);
  /* Fourth row */
  Hashtbl.add(values, "3-0", 3);
  Hashtbl.add(values, "3-1", 7);
  Hashtbl.add(values, "3-6", 5);
  /* Fifth row */
  Hashtbl.add(values, "4-0", 6);
  Hashtbl.add(values, "4-8", 4);
  /* Sixth row */
  Hashtbl.add(values, "5-2", 8);
  Hashtbl.add(values, "5-7", 1);
  Hashtbl.add(values, "5-8", 3);
  /* Seventh row */
  Hashtbl.add(values, "6-4", 2);
  /* Eight row */
  Hashtbl.add(values, "7-2", 9);
  Hashtbl.add(values, "7-3", 8);
  Hashtbl.add(values, "7-7", 3);
  Hashtbl.add(values, "7-8", 6);
  /* Ninth row */
  Hashtbl.add(values, "8-3", 3);
  Hashtbl.add(values, "8-5", 6);
  Hashtbl.add(values, "8-7", 9);
  values;
};