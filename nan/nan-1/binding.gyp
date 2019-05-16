{
  "targets": [
    {
      "target_name": "nan1",
      "sources": [ "nan1.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}