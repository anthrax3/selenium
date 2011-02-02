/* AUTO GENERATED - Do not edit by hand. */
/* See rake-tasks/crazy_fun/mappings/javascript.rb for generator. */

#ifndef SIZZLE_H
#define SIZZLE_H

const wchar_t* SIZZLE[] = {
L"/*!",
L" * Sizzle CSS Selector Engine - v1.0",
L" *  Copyright 2009, The Dojo Foundation",
L" *  Released under the MIT, BSD, and GPL Licenses.",
L" *  More information: http://sizzlejs.com/",
L" */",
L"(function(){",
L"",
L"var chunker = /((?:\\((?:\\([^()]+\\)|[^()]+)+\\)|\\[(?:\\[[^\\[\\]]*\\]|['\"][^'\"]*['\"]|[^\\[\\]'\"]+)+\\]|\\\\.|[^ >+~,(\\[\\\\]+)+|[>+~])(\\s*,\\s*)?((?:.|\\r|\\n)*)/g,",
L"	done = 0,",
L"	toString = Object.prototype.toString,",
L"	hasDuplicate = false,",
L"	baseHasDuplicate = true;",
L"",
L"// Here we check if the JavaScript engine is using some sort of",
L"// optimization where it does not always call our comparision",
L"// function. If that is the case, discard the hasDuplicate value.",
L"//   Thus far that includes Google Chrome.",
L"[0, 0].sort(function(){",
L"	baseHasDuplicate = false;",
L"	return 0;",
L"});",
L"",
L"var Sizzle = function(selector, context, results, seed) {",
L"	results = results || [];",
L"	context = context || document;",
L"",
L"	var origContext = context;",
L"",
L"	if ( context.nodeType !== 1 && context.nodeType !== 9 ) {",
L"		return [];",
L"	}",
L"	",
L"	if ( !selector || typeof selector !== \"string\" ) {",
L"		return results;",
L"	}",
L"",
L"	var parts = [], m, set, checkSet, extra, prune = true, contextXML = Sizzle.isXML(context),",
L"		soFar = selector, ret, cur, pop, i;",
L"	",
L"	// Reset the position of the chunker regexp (start from head)",
L"	do {",
L"		chunker.exec(\"\");",
L"		m = chunker.exec(soFar);",
L"",
L"		if ( m ) {",
L"			soFar = m[3];",
L"		",
L"			parts.push( m[1] );",
L"		",
L"			if ( m[2] ) {",
L"				extra = m[3];",
L"				break;",
L"			}",
L"		}",
L"	} while ( m );",
L"",
L"	if ( parts.length > 1 && origPOS.exec( selector ) ) {",
L"		if ( parts.length === 2 && Expr.relative[ parts[0] ] ) {",
L"			set = posProcess( parts[0] + parts[1], context );",
L"		} else {",
L"			set = Expr.relative[ parts[0] ] ?",
L"				[ context ] :",
L"				Sizzle( parts.shift(), context );",
L"",
L"			while ( parts.length ) {",
L"				selector = parts.shift();",
L"",
L"				if ( Expr.relative[ selector ] ) {",
L"					selector += parts.shift();",
L"				}",
L"				",
L"				set = posProcess( selector, set );",
L"			}",
L"		}",
L"	} else {",
L"		// Take a shortcut and set the context if the root selector is an ID",
L"		// (but not if it'll be faster if the inner selector is an ID)",
L"		if ( !seed && parts.length > 1 && context.nodeType === 9 && !contextXML &&",
L"				Expr.match.ID.test(parts[0]) && !Expr.match.ID.test(parts[parts.length - 1]) ) {",
L"			ret = Sizzle.find( parts.shift(), context, contextXML );",
L"			context = ret.expr ? Sizzle.filter( ret.expr, ret.set )[0] : ret.set[0];",
L"		}",
L"",
L"		if ( context ) {",
L"			ret = seed ?",
L"				{ expr: parts.pop(), set: makeArray(seed) } :",
L"				Sizzle.find( parts.pop(), parts.length === 1 && (parts[0] === \"~\" || parts[0] === \"+\") && context.parentNode ? context.parentNode : context, contextXML );",
L"			set = ret.expr ? Sizzle.filter( ret.expr, ret.set ) : ret.set;",
L"",
L"			if ( parts.length > 0 ) {",
L"				checkSet = makeArray(set);",
L"			} else {",
L"				prune = false;",
L"			}",
L"",
L"			while ( parts.length ) {",
L"				cur = parts.pop();",
L"				pop = cur;",
L"",
L"				if ( !Expr.relative[ cur ] ) {",
L"					cur = \"\";",
L"				} else {",
L"					pop = parts.pop();",
L"				}",
L"",
L"				if ( pop == null ) {",
L"					pop = context;",
L"				}",
L"",
L"				Expr.relative[ cur ]( checkSet, pop, contextXML );",
L"			}",
L"		} else {",
L"			checkSet = parts = [];",
L"		}",
L"	}",
L"",
L"	if ( !checkSet ) {",
L"		checkSet = set;",
L"	}",
L"",
L"	if ( !checkSet ) {",
L"		Sizzle.error( cur || selector );",
L"	}",
L"",
L"	if ( toString.call(checkSet) === \"[object Array]\" ) {",
L"		if ( !prune ) {",
L"			results.push.apply( results, checkSet );",
L"		} else if ( context && context.nodeType === 1 ) {",
L"			for ( i = 0; checkSet[i] != null; i++ ) {",
L"				if ( checkSet[i] && (checkSet[i] === true || checkSet[i].nodeType === 1 && Sizzle.contains(context, checkSet[i])) ) {",
L"					results.push( set[i] );",
L"				}",
L"			}",
L"		} else {",
L"			for ( i = 0; checkSet[i] != null; i++ ) {",
L"				if ( checkSet[i] && checkSet[i].nodeType === 1 ) {",
L"					results.push( set[i] );",
L"				}",
L"			}",
L"		}",
L"	} else {",
L"		makeArray( checkSet, results );",
L"	}",
L"",
L"	if ( extra ) {",
L"		Sizzle( extra, origContext, results, seed );",
L"		Sizzle.uniqueSort( results );",
L"	}",
L"",
L"	return results;",
L"};",
L"",
L"Sizzle.uniqueSort = function(results){",
L"	if ( sortOrder ) {",
L"		hasDuplicate = baseHasDuplicate;",
L"		results.sort(sortOrder);",
L"",
L"		if ( hasDuplicate ) {",
L"			for ( var i = 1; i < results.length; i++ ) {",
L"				if ( results[i] === results[i-1] ) {",
L"					results.splice(i--, 1);",
L"				}",
L"			}",
L"		}",
L"	}",
L"",
L"	return results;",
L"};",
L"",
L"Sizzle.matches = function(expr, set){",
L"	return Sizzle(expr, null, null, set);",
L"};",
L"",
L"Sizzle.find = function(expr, context, isXML){",
L"	var set;",
L"",
L"	if ( !expr ) {",
L"		return [];",
L"	}",
L"",
L"	for ( var i = 0, l = Expr.order.length; i < l; i++ ) {",
L"		var type = Expr.order[i], match;",
L"		",
L"		if ( (match = Expr.leftMatch[ type ].exec( expr )) ) {",
L"			var left = match[1];",
L"			match.splice(1,1);",
L"",
L"			if ( left.substr( left.length - 1 ) !== \"\\\\\" ) {",
L"				match[1] = (match[1] || \"\").replace(/\\\\/g, \"\");",
L"				set = Expr.find[ type ]( match, context, isXML );",
L"				if ( set != null ) {",
L"					expr = expr.replace( Expr.match[ type ], \"\" );",
L"					break;",
L"				}",
L"			}",
L"		}",
L"	}",
L"",
L"	if ( !set ) {",
L"		set = context.getElementsByTagName(\"*\");",
L"	}",
L"",
L"	return {set: set, expr: expr};",
L"};",
L"",
L"Sizzle.filter = function(expr, set, inplace, not){",
L"	var old = expr, result = [], curLoop = set, match, anyFound,",
L"		isXMLFilter = set && set[0] && Sizzle.isXML(set[0]);",
L"",
L"	while ( expr && set.length ) {",
L"		for ( var type in Expr.filter ) {",
L"			if ( (match = Expr.leftMatch[ type ].exec( expr )) != null && match[2] ) {",
L"				var filter = Expr.filter[ type ], found, item, left = match[1];",
L"				anyFound = false;",
L"",
L"				match.splice(1,1);",
L"",
L"				if ( left.substr( left.length - 1 ) === \"\\\\\" ) {",
L"					continue;",
L"				}",
L"",
L"				if ( curLoop === result ) {",
L"					result = [];",
L"				}",
L"",
L"				if ( Expr.preFilter[ type ] ) {",
L"					match = Expr.preFilter[ type ]( match, curLoop, inplace, result, not, isXMLFilter );",
L"",
L"					if ( !match ) {",
L"						anyFound = found = true;",
L"					} else if ( match === true ) {",
L"						continue;",
L"					}",
L"				}",
L"",
L"				if ( match ) {",
L"					for ( var i = 0; (item = curLoop[i]) != null; i++ ) {",
L"						if ( item ) {",
L"							found = filter( item, match, i, curLoop );",
L"							var pass = not ^ !!found;",
L"",
L"							if ( inplace && found != null ) {",
L"								if ( pass ) {",
L"									anyFound = true;",
L"								} else {",
L"									curLoop[i] = false;",
L"								}",
L"							} else if ( pass ) {",
L"								result.push( item );",
L"								anyFound = true;",
L"							}",
L"						}",
L"					}",
L"				}",
L"",
L"				if ( found !== undefined ) {",
L"					if ( !inplace ) {",
L"						curLoop = result;",
L"					}",
L"",
L"					expr = expr.replace( Expr.match[ type ], \"\" );",
L"",
L"					if ( !anyFound ) {",
L"						return [];",
L"					}",
L"",
L"					break;",
L"				}",
L"			}",
L"		}",
L"",
L"		// Improper expression",
L"		if ( expr === old ) {",
L"			if ( anyFound == null ) {",
L"				Sizzle.error( expr );",
L"			} else {",
L"				break;",
L"			}",
L"		}",
L"",
L"		old = expr;",
L"	}",
L"",
L"	return curLoop;",
L"};",
L"",
L"Sizzle.error = function( msg ) {",
L"	throw \"Syntax error, unrecognized expression: \" + msg;",
L"};",
L"",
L"var Expr = Sizzle.selectors = {",
L"	order: [ \"ID\", \"NAME\", \"TAG\" ],",
L"	match: {",
L"		ID: /#((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)/,",
L"		CLASS: /\\.((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)/,",
L"		NAME: /\\[name=['\"]*((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)['\"]*\\]/,",
L"		ATTR: /\\[\\s*((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)\\s*(?:(\\S?=)\\s*(['\"]*)(.*?)\\3|)\\s*\\]/,",
L"		TAG: /^((?:[\\w\\u00c0-\\uFFFF\\*\\-]|\\\\.)+)/,",
L"		CHILD: /:(only|nth|last|first)-child(?:\\((even|odd|[\\dn+\\-]*)\\))?/,",
L"		POS: /:(nth|eq|gt|lt|first|last|even|odd)(?:\\((\\d*)\\))?(?=[^\\-]|$)/,",
L"		PSEUDO: /:((?:[\\w\\u00c0-\\uFFFF\\-]|\\\\.)+)(?:\\((['\"]?)((?:\\([^\\)]+\\)|[^\\(\\)]*)+)\\2\\))?/",
L"	},",
L"	leftMatch: {},",
L"	attrMap: {",
L"		\"class\": \"className\",",
L"		\"for\": \"htmlFor\"",
L"	},",
L"	attrHandle: {",
L"		href: function(elem){",
L"			return elem.getAttribute(\"href\");",
L"		}",
L"	},",
L"	relative: {",
L"		\"+\": function(checkSet, part){",
L"			var isPartStr = typeof part === \"string\",",
L"				isTag = isPartStr && !/\\W/.test(part),",
L"				isPartStrNotTag = isPartStr && !isTag;",
L"",
L"			if ( isTag ) {",
L"				part = part.toLowerCase();",
L"			}",
L"",
L"			for ( var i = 0, l = checkSet.length, elem; i < l; i++ ) {",
L"				if ( (elem = checkSet[i]) ) {",
L"					while ( (elem = elem.previousSibling) && elem.nodeType !== 1 ) {}",
L"",
L"					checkSet[i] = isPartStrNotTag || elem && elem.nodeName.toLowerCase() === part ?",
L"						elem || false :",
L"						elem === part;",
L"				}",
L"			}",
L"",
L"			if ( isPartStrNotTag ) {",
L"				Sizzle.filter( part, checkSet, true );",
L"			}",
L"		},",
L"		\">\": function(checkSet, part){",
L"			var isPartStr = typeof part === \"string\",",
L"				elem, i = 0, l = checkSet.length;",
L"",
L"			if ( isPartStr && !/\\W/.test(part) ) {",
L"				part = part.toLowerCase();",
L"",
L"				for ( ; i < l; i++ ) {",
L"					elem = checkSet[i];",
L"					if ( elem ) {",
L"						var parent = elem.parentNode;",
L"						checkSet[i] = parent.nodeName.toLowerCase() === part ? parent : false;",
L"					}",
L"				}",
L"			} else {",
L"				for ( ; i < l; i++ ) {",
L"					elem = checkSet[i];",
L"					if ( elem ) {",
L"						checkSet[i] = isPartStr ?",
L"							elem.parentNode :",
L"							elem.parentNode === part;",
L"					}",
L"				}",
L"",
L"				if ( isPartStr ) {",
L"					Sizzle.filter( part, checkSet, true );",
L"				}",
L"			}",
L"		},",
L"		\"\": function(checkSet, part, isXML){",
L"			var doneName = done++, checkFn = dirCheck, nodeCheck;",
L"",
L"			if ( typeof part === \"string\" && !/\\W/.test(part) ) {",
L"				part = part.toLowerCase();",
L"				nodeCheck = part;",
L"				checkFn = dirNodeCheck;",
L"			}",
L"",
L"			checkFn(\"parentNode\", part, doneName, checkSet, nodeCheck, isXML);",
L"		},",
L"		\"~\": function(checkSet, part, isXML){",
L"			var doneName = done++, checkFn = dirCheck, nodeCheck;",
L"",
L"			if ( typeof part === \"string\" && !/\\W/.test(part) ) {",
L"				part = part.toLowerCase();",
L"				nodeCheck = part;",
L"				checkFn = dirNodeCheck;",
L"			}",
L"",
L"			checkFn(\"previousSibling\", part, doneName, checkSet, nodeCheck, isXML);",
L"		}",
L"	},",
L"	find: {",
L"		ID: function(match, context, isXML){",
L"			if ( typeof context.getElementById !== \"undefined\" && !isXML ) {",
L"				var m = context.getElementById(match[1]);",
L"				// Check parentNode to catch when Blackberry 4.6 returns",
L"				// nodes that are no longer in the document #6963",
L"				return m && m.parentNode ? [m] : [];",
L"			}",
L"		},",
L"		NAME: function(match, context){",
L"			if ( typeof context.getElementsByName !== \"undefined\" ) {",
L"				var ret = [], results = context.getElementsByName(match[1]);",
L"",
L"				for ( var i = 0, l = results.length; i < l; i++ ) {",
L"					if ( results[i].getAttribute(\"name\") === match[1] ) {",
L"						ret.push( results[i] );",
L"					}",
L"				}",
L"",
L"				return ret.length === 0 ? null : ret;",
L"			}",
L"		},",
L"		TAG: function(match, context){",
L"			return context.getElementsByTagName(match[1]);",
L"		}",
L"	},",
L"	preFilter: {",
L"		CLASS: function(match, curLoop, inplace, result, not, isXML){",
L"			match = \" \" + match[1].replace(/\\\\/g, \"\") + \" \";",
L"",
L"			if ( isXML ) {",
L"				return match;",
L"			}",
L"",
L"			for ( var i = 0, elem; (elem = curLoop[i]) != null; i++ ) {",
L"				if ( elem ) {",
L"					if ( not ^ (elem.className && (\" \" + elem.className + \" \").replace(/[\\t\\n]/g, \" \").indexOf(match) >= 0) ) {",
L"						if ( !inplace ) {",
L"							result.push( elem );",
L"						}",
L"					} else if ( inplace ) {",
L"						curLoop[i] = false;",
L"					}",
L"				}",
L"			}",
L"",
L"			return false;",
L"		},",
L"		ID: function(match){",
L"			return match[1].replace(/\\\\/g, \"\");",
L"		},",
L"		TAG: function(match, curLoop){",
L"			return match[1].toLowerCase();",
L"		},",
L"		CHILD: function(match){",
L"			if ( match[1] === \"nth\" ) {",
L"				// parse equations like 'even', 'odd', '5', '2n', '3n+2', '4n-1', '-n+6'",
L"				var test = /(-?)(\\d*)n((?:\\+|-)?\\d*)/.exec(",
L"					match[2] === \"even\" && \"2n\" || match[2] === \"odd\" && \"2n+1\" ||",
L"					!/\\D/.test( match[2] ) && \"0n+\" + match[2] || match[2]);",
L"",
L"				// calculate the numbers (first)n+(last) including if they are negative",
L"				match[2] = (test[1] + (test[2] || 1)) - 0;",
L"				match[3] = test[3] - 0;",
L"			}",
L"",
L"			// TODO: Move to normal caching system",
L"			match[0] = done++;",
L"",
L"			return match;",
L"		},",
L"		ATTR: function(match, curLoop, inplace, result, not, isXML){",
L"			var name = match[1].replace(/\\\\/g, \"\");",
L"			",
L"			if ( !isXML && Expr.attrMap[name] ) {",
L"				match[1] = Expr.attrMap[name];",
L"			}",
L"",
L"			if ( match[2] === \"~=\" ) {",
L"				match[4] = \" \" + match[4] + \" \";",
L"			}",
L"",
L"			return match;",
L"		},",
L"		PSEUDO: function(match, curLoop, inplace, result, not){",
L"			if ( match[1] === \"not\" ) {",
L"				// If we're dealing with a complex expression, or a simple one",
L"				if ( ( chunker.exec(match[3]) || \"\" ).length > 1 || /^\\w/.test(match[3]) ) {",
L"					match[3] = Sizzle(match[3], null, null, curLoop);",
L"				} else {",
L"					var ret = Sizzle.filter(match[3], curLoop, inplace, true ^ not);",
L"					if ( !inplace ) {",
L"						result.push.apply( result, ret );",
L"					}",
L"					return false;",
L"				}",
L"			} else if ( Expr.match.POS.test( match[0] ) || Expr.match.CHILD.test( match[0] ) ) {",
L"				return true;",
L"			}",
L"			",
L"			return match;",
L"		},",
L"		POS: function(match){",
L"			match.unshift( true );",
L"			return match;",
L"		}",
L"	},",
L"	filters: {",
L"		enabled: function(elem){",
L"			return elem.disabled === false && elem.type !== \"hidden\";",
L"		},",
L"		disabled: function(elem){",
L"			return elem.disabled === true;",
L"		},",
L"		checked: function(elem){",
L"			return elem.checked === true;",
L"		},",
L"		selected: function(elem){",
L"			// Accessing this property makes selected-by-default",
L"			// options in Safari work properly",
L"			elem.parentNode.selectedIndex;",
L"			return elem.selected === true;",
L"		},",
L"		parent: function(elem){",
L"			return !!elem.firstChild;",
L"		},",
L"		empty: function(elem){",
L"			return !elem.firstChild;",
L"		},",
L"		has: function(elem, i, match){",
L"			return !!Sizzle( match[3], elem ).length;",
L"		},",
L"		header: function(elem){",
L"			return (/h\\d/i).test( elem.nodeName );",
L"		},",
L"		text: function(elem){",
L"			return \"text\" === elem.type;",
L"		},",
L"		radio: function(elem){",
L"			return \"radio\" === elem.type;",
L"		},",
L"		checkbox: function(elem){",
L"			return \"checkbox\" === elem.type;",
L"		},",
L"		file: function(elem){",
L"			return \"file\" === elem.type;",
L"		},",
L"		password: function(elem){",
L"			return \"password\" === elem.type;",
L"		},",
L"		submit: function(elem){",
L"			return \"submit\" === elem.type;",
L"		},",
L"		image: function(elem){",
L"			return \"image\" === elem.type;",
L"		},",
L"		reset: function(elem){",
L"			return \"reset\" === elem.type;",
L"		},",
L"		button: function(elem){",
L"			return \"button\" === elem.type || elem.nodeName.toLowerCase() === \"button\";",
L"		},",
L"		input: function(elem){",
L"			return (/input|select|textarea|button/i).test(elem.nodeName);",
L"		}",
L"	},",
L"	setFilters: {",
L"		first: function(elem, i){",
L"			return i === 0;",
L"		},",
L"		last: function(elem, i, match, array){",
L"			return i === array.length - 1;",
L"		},",
L"		even: function(elem, i){",
L"			return i % 2 === 0;",
L"		},",
L"		odd: function(elem, i){",
L"			return i % 2 === 1;",
L"		},",
L"		lt: function(elem, i, match){",
L"			return i < match[3] - 0;",
L"		},",
L"		gt: function(elem, i, match){",
L"			return i > match[3] - 0;",
L"		},",
L"		nth: function(elem, i, match){",
L"			return match[3] - 0 === i;",
L"		},",
L"		eq: function(elem, i, match){",
L"			return match[3] - 0 === i;",
L"		}",
L"	},",
L"	filter: {",
L"		PSEUDO: function(elem, match, i, array){",
L"			var name = match[1], filter = Expr.filters[ name ];",
L"",
L"			if ( filter ) {",
L"				return filter( elem, i, match, array );",
L"			} else if ( name === \"contains\" ) {",
L"				return (elem.textContent || elem.innerText || Sizzle.getText([ elem ]) || \"\").indexOf(match[3]) >= 0;",
L"			} else if ( name === \"not\" ) {",
L"				var not = match[3];",
L"",
L"				for ( var j = 0, l = not.length; j < l; j++ ) {",
L"					if ( not[j] === elem ) {",
L"						return false;",
L"					}",
L"				}",
L"",
L"				return true;",
L"			} else {",
L"				Sizzle.error( \"Syntax error, unrecognized expression: \" + name );",
L"			}",
L"		},",
L"		CHILD: function(elem, match){",
L"			var type = match[1], node = elem;",
L"			switch (type) {",
L"				case 'only':",
L"				case 'first':",
L"					while ( (node = node.previousSibling) )	 {",
L"						if ( node.nodeType === 1 ) { ",
L"							return false; ",
L"						}",
L"					}",
L"					if ( type === \"first\" ) { ",
L"						return true; ",
L"					}",
L"					node = elem;",
L"				case 'last':",
L"					while ( (node = node.nextSibling) )	 {",
L"						if ( node.nodeType === 1 ) { ",
L"							return false; ",
L"						}",
L"					}",
L"					return true;",
L"				case 'nth':",
L"					var first = match[2], last = match[3];",
L"",
L"					if ( first === 1 && last === 0 ) {",
L"						return true;",
L"					}",
L"					",
L"					var doneName = match[0],",
L"						parent = elem.parentNode;",
L"	",
L"					if ( parent && (parent.sizcache !== doneName || !elem.nodeIndex) ) {",
L"						var count = 0;",
L"						for ( node = parent.firstChild; node; node = node.nextSibling ) {",
L"							if ( node.nodeType === 1 ) {",
L"								node.nodeIndex = ++count;",
L"							}",
L"						} ",
L"						parent.sizcache = doneName;",
L"					}",
L"					",
L"					var diff = elem.nodeIndex - last;",
L"					if ( first === 0 ) {",
L"						return diff === 0;",
L"					} else {",
L"						return ( diff % first === 0 && diff / first >= 0 );",
L"					}",
L"			}",
L"		},",
L"		ID: function(elem, match){",
L"			return elem.nodeType === 1 && elem.getAttribute(\"id\") === match;",
L"		},",
L"		TAG: function(elem, match){",
L"			return (match === \"*\" && elem.nodeType === 1) || elem.nodeName.toLowerCase() === match;",
L"		},",
L"		CLASS: function(elem, match){",
L"			return (\" \" + (elem.className || elem.getAttribute(\"class\")) + \" \")",
L"				.indexOf( match ) > -1;",
L"		},",
L"		ATTR: function(elem, match){",
L"			var name = match[1],",
L"				result = Expr.attrHandle[ name ] ?",
L"					Expr.attrHandle[ name ]( elem ) :",
L"					elem[ name ] != null ?",
L"						elem[ name ] :",
L"						elem.getAttribute( name ),",
L"				value = result + \"\",",
L"				type = match[2],",
L"				check = match[4];",
L"",
L"			return result == null ?",
L"				type === \"!=\" :",
L"				type === \"=\" ?",
L"				value === check :",
L"				type === \"*=\" ?",
L"				value.indexOf(check) >= 0 :",
L"				type === \"~=\" ?",
L"				(\" \" + value + \" \").indexOf(check) >= 0 :",
L"				!check ?",
L"				value && result !== false :",
L"				type === \"!=\" ?",
L"				value !== check :",
L"				type === \"^=\" ?",
L"				value.indexOf(check) === 0 :",
L"				type === \"$=\" ?",
L"				value.substr(value.length - check.length) === check :",
L"				type === \"|=\" ?",
L"				value === check || value.substr(0, check.length + 1) === check + \"-\" :",
L"				false;",
L"		},",
L"		POS: function(elem, match, i, array){",
L"			var name = match[2], filter = Expr.setFilters[ name ];",
L"",
L"			if ( filter ) {",
L"				return filter( elem, i, match, array );",
L"			}",
L"		}",
L"	}",
L"};",
L"",
L"var origPOS = Expr.match.POS,",
L"	fescape = function(all, num){",
L"		return \"\\\\\" + (num - 0 + 1);",
L"	};",
L"",
L"for ( var type in Expr.match ) {",
L"	Expr.match[ type ] = new RegExp( Expr.match[ type ].source + (/(?![^\\[]*\\])(?![^\\(]*\\))/.source) );",
L"	Expr.leftMatch[ type ] = new RegExp( /(^(?:.|\\r|\\n)*?)/.source + Expr.match[ type ].source.replace(/\\\\(\\d+)/g, fescape) );",
L"}",
L"",
L"var makeArray = function(array, results) {",
L"	array = Array.prototype.slice.call( array, 0 );",
L"",
L"	if ( results ) {",
L"		results.push.apply( results, array );",
L"		return results;",
L"	}",
L"	",
L"	return array;",
L"};",
L"",
L"// Perform a simple check to determine if the browser is capable of",
L"// converting a NodeList to an array using builtin methods.",
L"// Also verifies that the returned array holds DOM nodes",
L"// (which is not the case in the Blackberry browser)",
L"try {",
L"	Array.prototype.slice.call( document.documentElement.childNodes, 0 )[0].nodeType;",
L"",
L"// Provide a fallback method if it does not work",
L"} catch(e){",
L"	makeArray = function(array, results) {",
L"		var ret = results || [], i = 0;",
L"",
L"		if ( toString.call(array) === \"[object Array]\" ) {",
L"			Array.prototype.push.apply( ret, array );",
L"		} else {",
L"			if ( typeof array.length === \"number\" ) {",
L"				for ( var l = array.length; i < l; i++ ) {",
L"					ret.push( array[i] );",
L"				}",
L"			} else {",
L"				for ( ; array[i]; i++ ) {",
L"					ret.push( array[i] );",
L"				}",
L"			}",
L"		}",
L"",
L"		return ret;",
L"	};",
L"}",
L"",
L"var sortOrder, siblingCheck;",
L"",
L"if ( document.documentElement.compareDocumentPosition ) {",
L"	sortOrder = function( a, b ) {",
L"		if ( a === b ) {",
L"			hasDuplicate = true;",
L"			return 0;",
L"		}",
L"",
L"		if ( !a.compareDocumentPosition || !b.compareDocumentPosition ) {",
L"			return a.compareDocumentPosition ? -1 : 1;",
L"		}",
L"",
L"		return a.compareDocumentPosition(b) & 4 ? -1 : 1;",
L"	};",
L"} else {",
L"	sortOrder = function( a, b ) {",
L"		var ap = [], bp = [], aup = a.parentNode, bup = b.parentNode,",
L"			cur = aup, al, bl;",
L"",
L"		// The nodes are identical, we can exit early",
L"		if ( a === b ) {",
L"			hasDuplicate = true;",
L"			return 0;",
L"",
L"		// If the nodes are siblings (or identical) we can do a quick check",
L"		} else if ( aup === bup ) {",
L"			return siblingCheck( a, b );",
L"",
L"		// If no parents were found then the nodes are disconnected",
L"		} else if ( !aup ) {",
L"			return -1;",
L"",
L"		} else if ( !bup ) {",
L"			return 1;",
L"		}",
L"",
L"		// Otherwise they're somewhere else in the tree so we need",
L"		// to build up a full list of the parentNodes for comparison",
L"		while ( cur ) {",
L"			ap.unshift( cur );",
L"			cur = cur.parentNode;",
L"		}",
L"",
L"		cur = bup;",
L"",
L"		while ( cur ) {",
L"			bp.unshift( cur );",
L"			cur = cur.parentNode;",
L"		}",
L"",
L"		al = ap.length;",
L"		bl = bp.length;",
L"",
L"		// Start walking down the tree looking for a discrepancy",
L"		for ( var i = 0; i < al && i < bl; i++ ) {",
L"			if ( ap[i] !== bp[i] ) {",
L"				return siblingCheck( ap[i], bp[i] );",
L"			}",
L"		}",
L"",
L"		// We ended someplace up the tree so do a sibling check",
L"		return i === al ?",
L"			siblingCheck( a, bp[i], -1 ) :",
L"			siblingCheck( ap[i], b, 1 );",
L"	};",
L"",
L"	siblingCheck = function( a, b, ret ) {",
L"		if ( a === b ) {",
L"			return ret;",
L"		}",
L"",
L"		var cur = a.nextSibling;",
L"",
L"		while ( cur ) {",
L"			if ( cur === b ) {",
L"				return -1;",
L"			}",
L"",
L"			cur = cur.nextSibling;",
L"		}",
L"",
L"		return 1;",
L"	};",
L"}",
L"",
L"// Utility function for retreiving the text value of an array of DOM nodes",
L"Sizzle.getText = function( elems ) {",
L"	var ret = \"\", elem;",
L"",
L"	for ( var i = 0; elems[i]; i++ ) {",
L"		elem = elems[i];",
L"",
L"		// Get the text from text nodes and CDATA nodes",
L"		if ( elem.nodeType === 3 || elem.nodeType === 4 ) {",
L"			ret += elem.nodeValue;",
L"",
L"		// Traverse everything else, except comment nodes",
L"		} else if ( elem.nodeType !== 8 ) {",
L"			ret += Sizzle.getText( elem.childNodes );",
L"		}",
L"	}",
L"",
L"	return ret;",
L"};",
L"",
L"// Check to see if the browser returns elements by name when",
L"// querying by getElementById (and provide a workaround)",
L"(function(){",
L"	// We're going to inject a fake input element with a specified name",
L"	var form = document.createElement(\"div\"),",
L"		id = \"script\" + (new Date()).getTime();",
L"	form.innerHTML = \"<a name='\" + id + \"'/>\";",
L"",
L"	// Inject it into the root element, check its status, and remove it quickly",
L"	var root = document.documentElement;",
L"	root.insertBefore( form, root.firstChild );",
L"",
L"	// The workaround has to do additional checks after a getElementById",
L"	// Which slows things down for other browsers (hence the branching)",
L"	if ( document.getElementById( id ) ) {",
L"		Expr.find.ID = function(match, context, isXML){",
L"			if ( typeof context.getElementById !== \"undefined\" && !isXML ) {",
L"				var m = context.getElementById(match[1]);",
L"				return m ? m.id === match[1] || typeof m.getAttributeNode !== \"undefined\" && m.getAttributeNode(\"id\").nodeValue === match[1] ? [m] : undefined : [];",
L"			}",
L"		};",
L"",
L"		Expr.filter.ID = function(elem, match){",
L"			var node = typeof elem.getAttributeNode !== \"undefined\" && elem.getAttributeNode(\"id\");",
L"			return elem.nodeType === 1 && node && node.nodeValue === match;",
L"		};",
L"	}",
L"",
L"	root.removeChild( form );",
L"	root = form = null; // release memory in IE",
L"})();",
L"",
L"(function(){",
L"	// Check to see if the browser returns only elements",
L"	// when doing getElementsByTagName(\"*\")",
L"",
L"	// Create a fake element",
L"	var div = document.createElement(\"div\");",
L"	div.appendChild( document.createComment(\"\") );",
L"",
L"	// Make sure no comments are found",
L"	if ( div.getElementsByTagName(\"*\").length > 0 ) {",
L"		Expr.find.TAG = function(match, context){",
L"			var results = context.getElementsByTagName(match[1]);",
L"",
L"			// Filter out possible comments",
L"			if ( match[1] === \"*\" ) {",
L"				var tmp = [];",
L"",
L"				for ( var i = 0; results[i]; i++ ) {",
L"					if ( results[i].nodeType === 1 ) {",
L"						tmp.push( results[i] );",
L"					}",
L"				}",
L"",
L"				results = tmp;",
L"			}",
L"",
L"			return results;",
L"		};",
L"	}",
L"",
L"	// Check to see if an attribute returns normalized href attributes",
L"	div.innerHTML = \"<a href='#'></a>\";",
L"	if ( div.firstChild && typeof div.firstChild.getAttribute !== \"undefined\" &&",
L"			div.firstChild.getAttribute(\"href\") !== \"#\" ) {",
L"		Expr.attrHandle.href = function(elem){",
L"			return elem.getAttribute(\"href\", 2);",
L"		};",
L"	}",
L"",
L"	div = null; // release memory in IE",
L"})();",
L"",
L"if ( document.querySelectorAll ) {",
L"	(function(){",
L"		var oldSizzle = Sizzle, div = document.createElement(\"div\");",
L"		div.innerHTML = \"<p class='TEST'></p>\";",
L"",
L"		// Safari can't handle uppercase or unicode characters when",
L"		// in quirks mode.",
L"		if ( div.querySelectorAll && div.querySelectorAll(\".TEST\").length === 0 ) {",
L"			return;",
L"		}",
L"	",
L"		Sizzle = function(query, context, extra, seed){",
L"			context = context || document;",
L"",
L"			// Only use querySelectorAll on non-XML documents",
L"			// (ID selectors don't work in non-HTML documents)",
L"			if ( !seed && context.nodeType === 9 && !Sizzle.isXML(context) ) {",
L"				try {",
L"					return makeArray( context.querySelectorAll(query), extra );",
L"				} catch(e){}",
L"			}",
L"		",
L"			return oldSizzle(query, context, extra, seed);",
L"		};",
L"",
L"		for ( var prop in oldSizzle ) {",
L"			Sizzle[ prop ] = oldSizzle[ prop ];",
L"		}",
L"",
L"		div = null; // release memory in IE",
L"	})();",
L"}",
L"",
L"(function(){",
L"	var div = document.createElement(\"div\");",
L"",
L"	div.innerHTML = \"<div class='test e'></div><div class='test'></div>\";",
L"",
L"	// Opera can't find a second classname (in 9.6)",
L"	// Also, make sure that getElementsByClassName actually exists",
L"	if ( !div.getElementsByClassName || div.getElementsByClassName(\"e\").length === 0 ) {",
L"		return;",
L"	}",
L"",
L"	// Safari caches class attributes, doesn't catch changes (in 3.2)",
L"	div.lastChild.className = \"e\";",
L"",
L"	if ( div.getElementsByClassName(\"e\").length === 1 ) {",
L"		return;",
L"	}",
L"	",
L"	Expr.order.splice(1, 0, \"CLASS\");",
L"	Expr.find.CLASS = function(match, context, isXML) {",
L"		if ( typeof context.getElementsByClassName !== \"undefined\" && !isXML ) {",
L"			return context.getElementsByClassName(match[1]);",
L"		}",
L"	};",
L"",
L"	div = null; // release memory in IE",
L"})();",
L"",
L"function dirNodeCheck( dir, cur, doneName, checkSet, nodeCheck, isXML ) {",
L"	for ( var i = 0, l = checkSet.length; i < l; i++ ) {",
L"		var elem = checkSet[i];",
L"		if ( elem ) {",
L"			elem = elem[dir];",
L"			var match = false;",
L"",
L"			while ( elem ) {",
L"				if ( elem.sizcache === doneName ) {",
L"					match = checkSet[elem.sizset];",
L"					break;",
L"				}",
L"",
L"				if ( elem.nodeType === 1 && !isXML ){",
L"					elem.sizcache = doneName;",
L"					elem.sizset = i;",
L"				}",
L"",
L"				if ( elem.nodeName.toLowerCase() === cur ) {",
L"					match = elem;",
L"					break;",
L"				}",
L"",
L"				elem = elem[dir];",
L"			}",
L"",
L"			checkSet[i] = match;",
L"		}",
L"	}",
L"}",
L"",
L"function dirCheck( dir, cur, doneName, checkSet, nodeCheck, isXML ) {",
L"	for ( var i = 0, l = checkSet.length; i < l; i++ ) {",
L"		var elem = checkSet[i];",
L"		if ( elem ) {",
L"			elem = elem[dir];",
L"			var match = false;",
L"",
L"			while ( elem ) {",
L"				if ( elem.sizcache === doneName ) {",
L"					match = checkSet[elem.sizset];",
L"					break;",
L"				}",
L"",
L"				if ( elem.nodeType === 1 ) {",
L"					if ( !isXML ) {",
L"						elem.sizcache = doneName;",
L"						elem.sizset = i;",
L"					}",
L"					if ( typeof cur !== \"string\" ) {",
L"						if ( elem === cur ) {",
L"							match = true;",
L"							break;",
L"						}",
L"",
L"					} else if ( Sizzle.filter( cur, [elem] ).length > 0 ) {",
L"						match = elem;",
L"						break;",
L"					}",
L"				}",
L"",
L"				elem = elem[dir];",
L"			}",
L"",
L"			checkSet[i] = match;",
L"		}",
L"	}",
L"}",
L"",
L"Sizzle.contains = document.compareDocumentPosition ? function(a, b){",
L"	return !!(a.compareDocumentPosition(b) & 16);",
L"} : function(a, b){",
L"	return a !== b && (a.contains ? a.contains(b) : true);",
L"};",
L"",
L"Sizzle.isXML = function(elem){",
L"	// documentElement is verified for cases where it doesn't yet exist",
L"	// (such as loading iframes in IE - #4833) ",
L"	var documentElement = (elem ? elem.ownerDocument || elem : 0).documentElement;",
L"	return documentElement ? documentElement.nodeName !== \"HTML\" : false;",
L"};",
L"",
L"var posProcess = function(selector, context){",
L"	var tmpSet = [], later = \"\", match,",
L"		root = context.nodeType ? [context] : context;",
L"",
L"	// Position selectors must be done after the filter",
L"	// And so must :not(positional) so we move all PSEUDOs to the end",
L"	while ( (match = Expr.match.PSEUDO.exec( selector )) ) {",
L"		later += match[0];",
L"		selector = selector.replace( Expr.match.PSEUDO, \"\" );",
L"	}",
L"",
L"	selector = Expr.relative[selector] ? selector + \"*\" : selector;",
L"",
L"	for ( var i = 0, l = root.length; i < l; i++ ) {",
L"		Sizzle( selector, root[i], tmpSet );",
L"	}",
L"",
L"	return Sizzle.filter( later, tmpSet );",
L"};",
L"",
L"// EXPOSE",
L"",
L"window.Sizzle = Sizzle;",
L"",
L"})();",
NULL
};

#endif
