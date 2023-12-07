const char* DEFAULT_SYNTAX_GO =
    "api = [generic];\n"
    "api_style = [freeform, functions];\n"
    "jump_model = [goto_label, loop_switch];\n"
    "target = [code, dot];\n"
    "\n"
    "computed_goto = unsupported;\n"
    "case_ranges = unsupported;\n"
    "constants = upper_case;\n"
    "char_literals = (encoding.ebcdic ? hexadecimal : symbolic);\n"
    "semicolons = no;\n"
    "abort_requires_include = no;\n"
    "\n"
    "code:var = topindent (have_init? name \" := \" init : \"var \" name \" \" type) nl;\n"
    "\n"
    "code:const = topindent \"var \" name \" \" type \" = \" init nl;\n"
    "\n"
    "code:array =\n"
    "    topindent name \" := [\" size \"]\" type \"{\" nl indent\n"
    "        [row: topindent [elem{0:-2}: elem \", \"] [elem{-1}: elem \",\"] nl]\n"
    "    dedent topindent \"}\" nl;\n"
    "\n"
    "code:type_int = \"int\";\n"
    "code:type_uint = \"uint\";\n"
    "// code:type_cond_enum\n"
    "code:type_yybm = \"byte\";\n"
    "// code:type_yytarget\n"
    "\n"
    "code:if_then_else =\n"
    "    topindent \"if (\" then_cond \") {\" nl\n"
    "        indent [then_stmt: then_stmt] dedent\n"
    "    (have_else_part? topindent \"} else \" (have_else_cond? \"if (\" else_cond \") \") \"{\" nl\n"
    "        indent [else_stmt: else_stmt] dedent)\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch =\n"
    "    topindent \"switch (\" expr \") {\" nl\n"
    "    [case: case]\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases =\n"
    "    [case{0:-2}: topindent case nl\n"
    "        indent topindent \"fallthrough\" dedent nl]\n"
    "    [case{-1}: topindent case nl]\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:switch_case_range = \"case \" [val{0}: val] [val{1:-1}: \",\" val] \":\";\n"
    "\n"
    "code:switch_case_default = \"default:\";\n"
    "\n"
    "code:loop =\n"
    "    (have_label? label \":\" nl)\n"
    "    topindent \"for {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:enum =\n"
    "    \"const (\" nl indent\n"
    "        [elem{0}:    topindent elem \" = \" (have_init ? init : \"iota\") nl]\n"
    "        [elem{1:-1}: topindent elem (have_init ? \" = \" init) nl]\n"
    "    dedent \")\" nl;\n"
    "\n"
    "code:fingerprint =\n"
    "    \"// Code generated by re2c\"\n"
    "    (have_version? \" \" version)\n"
    "    (have_date? \" on \" date)\n"
    "    \", DO NOT EDIT.\" nl;\n"
    "\n"
    "code:line_info = \"//line \\\"\" file \"\\\":\" line nl;\n"
    "\n"
    "code:abort = topindent \"panic(\\\"internal lexer error\\\")\" nl;\n"
    "\n"
    "code:yypeek_expr = (api.generic\n"
    "    ? expr (api_style.functions ? \"()\")\n"
    "    : \"*\" expr );\n"
    ;
