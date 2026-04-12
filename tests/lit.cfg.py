import os
import lit.formats

config.name = 'cpp2rust'
config.test_format = lit.formats.Cpp2RustTest()
config.test_source_root = os.path.dirname(__file__)
