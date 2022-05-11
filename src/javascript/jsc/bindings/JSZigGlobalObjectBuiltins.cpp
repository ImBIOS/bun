/*
 * Copyright (c) 2016 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "JSZigGlobalObjectBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_jsZigGlobalObjectRequireCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_jsZigGlobalObjectRequireCodeConstructorKind = JSC::ConstructorKind::None;
const int s_jsZigGlobalObjectRequireCodeLength = 1225;
static const JSC::Intrinsic s_jsZigGlobalObjectRequireCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_jsZigGlobalObjectRequireCode =
    "(function (name) {\n" \
    "  \"use strict\";\n" \
    "  if (typeof name !== \"string\") {\n" \
    "    @throwTypeError(\"require() expects a string as its argument\");\n" \
    "  }\n" \
    "\n" \
    "  const resolved = this.resolveSync(name, this.path);\n" \
    "  var requireCache = (globalThis[Symbol.for(\"_requireCache\")] ||= new @Map);\n" \
    "  var cached = requireCache.@get(resolved);\n" \
    "  if (cached) {\n" \
    "    if (resolved.endsWith(\".node\")) {\n" \
    "      return cached.exports;\n" \
    "    }\n" \
    "\n" \
    "    return cached;\n" \
    "  }\n" \
    "\n" \
    "  //\n" \
    "  if (resolved.endsWith(\".json\")) {\n" \
    "    var fs = (globalThis[Symbol.for(\"_fs\")] ||= Bun.fs());\n" \
    "    var exports = JSON.parse(fs.readFileSync(resolved, \"utf8\"));\n" \
    "    requireCache.@set(resolved, exports);\n" \
    "    return exports;\n" \
    "  } else if (resolved.endsWith(\".node\")) {\n" \
    "    var module = { exports: {} };\n" \
    "    globalThis.process.dlopen(module, resolved);\n" \
    "    requireCache.@set(resolved, module);\n" \
    "    return module.exports;\n" \
    "  } else if (resolved.endsWith(\".toml\")) {\n" \
    "    var fs = (globalThis[Symbol.for(\"_fs\")] ||= Bun.fs());\n" \
    "    var exports = Bun.TOML.parse(fs.readFileSync(resolved, \"utf8\"));\n" \
    "    requireCache.@set(resolved, exports);\n" \
    "    return exports;\n" \
    "  }\n" \
    "\n" \
    "  @throwTypeError(`Dynamic require isn't supported for file type: ${resolved.subsring(resolved.lastIndexOf(\".\") + 1) || resolved}`);\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().jsZigGlobalObjectBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().jsZigGlobalObjectBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_JSZIGGLOBALOBJECT_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
