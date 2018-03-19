let one = {
  let values = Hashtbl.create(30);
  /* First row */
  Hashtbl.add(values, "0-3", 2);
  Hashtbl.add(values, "0-4", 6);
  Hashtbl.add(values, "0-6", 7);
  Hashtbl.add(values, "0-8", 1);
  /* Second row */
  Hashtbl.add(values, "1-0", 6);
  Hashtbl.add(values, "1-1", 8);
  Hashtbl.add(values, "1-4", 7);
  Hashtbl.add(values, "1-7", 9);
  /* Third row */
  Hashtbl.add(values, "2-0", 1);
  Hashtbl.add(values, "2-1", 9);
  Hashtbl.add(values, "2-5", 4);
  Hashtbl.add(values, "2-6", 5);
  /* Fourth row */
  Hashtbl.add(values, "3-0", 8);
  Hashtbl.add(values, "3-1", 2);
  Hashtbl.add(values, "3-3", 1);
  Hashtbl.add(values, "3-7", 4);
  /* Fifth row */
  Hashtbl.add(values, "4-2", 4);
  Hashtbl.add(values, "4-3", 6);
  Hashtbl.add(values, "4-5", 2);
  Hashtbl.add(values, "4-6", 9);
  /* Sixth row */
  Hashtbl.add(values, "5-1", 5);
  Hashtbl.add(values, "5-5", 3);
  Hashtbl.add(values, "5-7", 2);
  Hashtbl.add(values, "5-8", 8);
  /* Seventh row */
  Hashtbl.add(values, "6-2", 9);
  Hashtbl.add(values, "6-3", 3);
  Hashtbl.add(values, "6-7", 7);
  Hashtbl.add(values, "6-8", 4);
  /* Eight row */
  Hashtbl.add(values, "7-1", 4);
  Hashtbl.add(values, "7-4", 5);
  Hashtbl.add(values, "7-7", 3);
  Hashtbl.add(values, "7-8", 6);
  /* Ninth row */
  Hashtbl.add(values, "8-0", 7);
  Hashtbl.add(values, "8-2", 3);
  Hashtbl.add(values, "8-4", 1);
  Hashtbl.add(values, "8-5", 8);
  values;
};