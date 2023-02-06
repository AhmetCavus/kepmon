{
  "targets": [
    {
      "target_name": "pointerService",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./cpp/Os/OsResolver.cpp",
        "./cpp/Pointer/Command/PointerCommand.cpp",
        "./cpp/Pointer/Service/PointerServiceLocator.cpp",
        "./cpp/Pointer/Service/PointerServiceWin.cpp",
        "./cpp/Pointer/PointerCommandResult.cpp",
        "./cpp/index.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}