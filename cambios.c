// Argumentos de main
  int n = 15;

  int option_index;
  int c;

  static struct option long_options[] =
  {
    {"size", optional_argument, 0, 's'},
    { 0, 0, 0, 0 }
  };

  while ((c = getopt_long(argc, **argv, "s:", long_options,
                          &option_index)) != -1) {
    switch (c) {
    case 's':
      n = strtol(optagr, NULL, 0);
      break;
    default
      printf("ERROR\n");
      exit(EXIT_FAILURE);
    }
  }
