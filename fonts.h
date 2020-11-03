#define DEF_SPC 0
#define DEF_VIR 1
#define DEF_PCT 2
#define DEF_INT 3
#define DEF_EXL 4

char demoTab[10][10] = {
  {"    ##    "},
  {"    ##    "},
  {"  ######  "},
  {"  ##      "},
  {"  ######  "},
  {"  ######  "},
  {"      ##  "},
  {"  ######  "},
  {"    ##    "},
  {"    ##    "}
};

char fontTerminal[26][10][10] = {
  { /// a
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"    ##### "},
    {"  ####### "},
    {" ##   ### "},
    {"  ####### "},
    {"    ##### "},
    {"          "}
  },
  { /// b
    {"          "},
    {" ##       "},
    {" ##       "},
    {" ##       "},
    {" #####    "},
    {" #######  "},
    {" ##  #### "},
    {" #######  "},
    {" #####    "},
    {"          "}
  },
  { /// c
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"   ######" },
    {"  ####### "},
    {" ###      "},
    {"  ####### "},
    {"   ###### "},
    {"          "}
  },
  { /// d
    {"          "},
    {"       ## "},
    {"       ## "},
    {"       ## "},
    {"   ###### "},
    {"  ####### "},
    {" ###   ## "},
    {"  ####### "},
    {"   ###### "},
    {"          "}
  },
  { /// e
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"   ####   "},
    {"  ##  ##  "},
    {" ######## "},
    {"  ###     "},
    {"   #####  "},
    {"          "}
  },
  { /// f
    {"          "},
    {"  ####    "},
    {" ###  ##  "},
    {"  ##      "},
    {" #####    "},
    {"  ##      "},
    {"  ##      "},
    {"  ##      "},
    {"  ##      "},
    {"          "}
  },
  { /// g
    {"          "},
    {"          "},
    {"   ###### "},
    {"  ####### "},
    {" ###  ### "},
    {"  ####### "},
    {"   ###### "},
    {"      ### "},
    {"  ######  "},
    {"          "}
  },
  { /// h
    {"          "},
    {"  ##      "},
    {"  ##      "},
    {"  ##      "},
    {"  #####   "},
    {"  ##  ##  "},
    {"  ##  ##  "},
    {"  ##  ##  "},
    {"  ##  ##  "},
    {"          "}
  },
  { /// i
    {"          "},
    {"    ##    "},
    {"    ##    "},
    {"          "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"          "}
  },
  { /// j
    {"          "},
    {"      ### "},
    {"          "},
    {"      ### "},
    {"      ### "},
    {"      ### "},
    {"      ### "},
    {" ##   ### "},
    {"  ######  "},
    {"          "}
  },
  { /// k
    {"          "},
    {"  ##      "},
    {"  ##      "},
    {"  ##  ##  "},
    {"  ## ##   "},
    {"  ####    "},
    {"  ## ##   "},
    {"  ## ##   "},
    {"  ##  ##  "},
    {"          "}
  },
  { /// l
    {"          "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"          "}
  },
  { /// m
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" # ## ##  "},
    {" ## ## ## "},
    {" ## ## ## "},
    {" ## ## ## "},
    {" ## ## ## "},
    {"          "}
  },
  { /// n
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" #######  "},
    {" ###  ### "},
    {" ###  ### "},
    {" ###  ### "},
    {" ###  ### "},
    {"          "}
  },
  { /// o
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"   ####   "},
    {"  ######  "},
    {" ###  ### "},
    {"  ######  "},
    {"   ####   "},
    {"          "}
  },
  { /// p
    {"          "},
    {"          "},
    {" ######   "},
    {" #######  "},
    {" ##    ## "},
    {" #######  "},
    {" ######   "},
    {" ##       "},
    {" ##       "},
    {"          "}
  },
  { /// q
    {"          "},
    {"          "},
    {"   ###### "},
    {"  ####### "},
    {" ##    ## "},
    {"  ####### "},
    {"   ###### "},
    {"       ## "},
    {"       ## "},
    {"          "}
  },
  { /// r
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" # ####   "},
    {" ###  ##  "},
    {" ###      "},
    {" ###      "},
    {" ###      "},
    {"          "}
  },
  { /// s
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"  ######  "},
    {" ##       "},
    {"  ######  "},
    {"       ## "},
    {"  ######  "},
    {"          "}
  },
  { /// t
    {"          "},
    {"  ##      "},
    {"  ##      "},
    {"  ##      "},
    {" #####    "},
    {"  ##      "},
    {"  ##      "},
    {"  ####### "},
    {"   #####  "},
    {"          "}
  },
  { /// u
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" ##    ## "},
    {" ##    ## "},
    {" ##    ## "},
    {" ######## "},
    {"  ######  "},
    {"          "}
  },
  { /// v
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" ##    ## "},
    {" ##    ## "},
    {"  ##  ##  "},
    {"   ####   "},
    {"    ##    "},
    {"          "}
  },
  { /// w
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" ## ## ## "},
    {" ## ## ## "},
    {" ## ## ## "},
    {" ## ## ## "},
    {"  ##  ##  "},
    {"          "}
  },
  { /// x
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" ##    ## "},
    {"  ######  "},
    {"    ##    "},
    {"  ######  "},
    {" ##    ## "},
    {"          "}
  },
  { /// y
    {"          "},
    {"          "},
    {" ##    ## "},
    {" ##    ## "},
    {"  ##  ##  "},
    {"   ####   "},
    {"    ##    "},
    {"   ##     "},
    {"  ##      "},
    {"          "}
  },
  { /// z
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {" ######## "},
    {"      ##  "},
    {"    ###   "},
    {"  ###     "},
    {" ######## "},
    {"          "}
  }
};

char fontAdditional[5][10][10] = {
  { /// spatiu
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "}
  },
  { /// virgula ( , )
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"     ##   "},
    {"     ##   "},
    {"      #   "},
    {"    ###   "},
    {"          "}
  },
  { /// punct ( . )
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"    ##    "},
    {"    ##    "},
    {"          "},
    {"          "}
  },
  { /// semnul intrebarii ( ? )
    {"          "},
    {"    ###   "},
    {"   ## ##  "},
    {"       ## "},
    {"      ##  "},
    {"    ###   "},
    {"          "},
    {"    ##    "},
    {"    ##    "},
    {"          "}
  },
  { /// semn de exclamatie ( ! )
    {"          "},
    {"    ##    "},
    {"   ####   "},
    {"   ####   "},
    {"   ####   "},
    {"    ##    "},
    {"          "},
    {"    ##    "},
    {"    ##    "},
    {"          "}
  }
};

char fontNumbers[10][10][10] = {
  { /// 0
    {"          "},
    {"  ######  "},
    {" ######## "},
    {" ##    ## "},
    {" #   ## # "},
    {" # ##   # "},
    {" ##    ## "},
    {" ######## "},
    {"  ######  "},
    {"          "}
  },
  { /// 1
    {"          "},
    {"    ##    "},
    {"   ###    "},
    {"  ####    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {"    ##    "},
    {" ######## "},
    {"          "}
  },
  { /// 2
    {"          "},
    {"   ####   "},
    {"  ######  "},
    {" ##    ## "},
    {"       ## "},
    {"     ###  "},
    {"   ###    "},
    {" ###      "},
    {" ######## "},
    {"          "}
  },
  { /// 3
    {"          "},
    {"          "},
    {"   ####   "},
    {"  ##  ##  "},
    {"      ##  "},
    {"   ####   "},
    {"      ##  "},
    {"  ##  ##  "},
    {"   ####   "},
    {"          "}
  },
  { /// 4
    {"     ###  "},
    {"    ####  "},
    {"   ## ##  "},
    {"  ##  ##  "},
    {" ##   ##  "},
    {" ######## "},
    {"     ##   "},
    {"     ##   "},
    {"     ##   "},
    {"          "}
  },
  { /// 5
    {""},
    {" ######## "},
    {" ######## "},
    {" ##       "},
    {" ##       "},
    {"  ######  "},
    {"       ## "},
    {" ##    ## "},
    {"  ######  "},
    {"          "}
  },
  { /// 6
    {""},
    {"      ### "},
    {"     ##   "},
    {"    ##    "},
    {"   ##     "},
    {"  ######  "},
    {" ##    ## "},
    {" ##    ## "},
    {"  ######  "},
    {"          "}
  },
  { /// 7
    {"          "},
    {" ######## "},
    {" ######## "},
    {"       ## "},
    {"      ##  "},
    {"     ##   "},
    {"     ##   "},
    {"    ##    "},
    {"   ##     "},
    {"          "}
  },
  { /// 8
    {"          "},
    {"   ####   "},
    {"  ##  ##  "},
    {" ##    ## "},
    {"  ##  ##  "},
    {"  ######  "},
    {"  ##  ##  "},
    {" ##    ## "},
    {"  ##  ##  "},
    {"   ####   "}
  },
  { /// 9
    {"          "},
    {"   #####  "},
    {"  ##   ## "},
    {"  ##   ## "},
    {"   ###### "},
    {"       ## "},
    {"       ## "},
    {"      ### "},
    {"   #####  "},
    {"          "}
  },
};